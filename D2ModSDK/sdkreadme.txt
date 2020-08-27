D2ModSDK - @2004 SVR
--------------------

This SDK (Software Development Kit) will help you create mod dlls to use with the D2Mod.dll mod system for Diablo II.

It contains the following folders...

bin\ - contains d2mod.dll. Copy to your D2 folder.

lib\ - contains d2dlls.lib,d2mod.lib. These are the library containing the exports for the various d2 dll files to link with your mod. It will be linked in automatically.

include\ - these are the header files defining the exports. D2Mod.h is all you will need to include in your mod. The others will be included automatically.

Samples\ - these are sample mods. Examine these to understand how to use the system. A VC6 Workspace is included along with project files for each example.


BUILDING THE SAMPLES
--------------------

To build the samples, load the SAMPLES workspace and select the sample project you wish to build.
Right click the project and select properties. On the link tab, choose the general catagory and set the output path to your d2 folder. Click ok.

Now press F7 to build.


STARTING YOUR OWN MOD
---------------------

To start your own mod, copy the folder "MyMod". Rename it as you wish. Rename the files inside (MyMod.cpp & MyMod.h).
Right click the SAMPLES workspace and choose add new project. Pick Win32 Dynamic Link Library. Make sure the path is the samples folder and type the name of your new project (use the same name as your folder). 
Hit next, choose an empty project and hit finish.

Now right click your new project and add files to project. Select your .cpp & .h files.
You may search & replace MYMOD in the files with your mod name if you wish. You must change the #include "MyMod.h" to match your header filename.

Right click your project and choose settings. Pick the C/C++ tab and select "preprocessor" catagory. Set additional include path to "..\..\include".
Pick the link tab. Select the general catagory. Set the output filename to your d2 folder.
Select the input catagory. Set the additional library path to "..\..\lib".

You can set other settings as you like. Check the other samples for their settings.

Now you are ready to add code.


ADDING CODE EDITS
------------------

There is a section declared for each d2 dll that can be modified. You will insert your code edits in these sections.

Each edit is added as a record which contains three fields - {offset,value, fixuptype}.

The offset is the RVA (Relative Virtual Address) in the dll you want to change.

The value is the code bytes to enter. It is a DWORD so the bytes will be reverse order from the assembly listing.

The fixuptype tells the loader how to adjust the value. The three types are ...

FT_NON - no adjustment. Copy bytes as is.

FT_REL - Apply a relative fixup. It adust the value relative to the adress. Use this for relative jumps & calls to local C functions.

FT_FIX - Apply a fixed fixup. It subtracts the original/preferred base address of the dll from the value, then adds the actual base address. This allows jumps & calls to fixed addresses within a module and also fixed data references.

All edit values MUST be 4 bytes in reverse order. This can lead to confusion sometimes trying to enter code bytes from a listing.

Here is an example listing ...

00BCA0 50		PUSH    EAX
00BCA1 68 30BDA76F	PUSH    d2gfx.6FA7BD30                   ;  ASCII "D2Mod.dll"
00BCA6 FF15 40C0A76F    CALL    [<&KERNEL32.LoadLibraryA>]       ;  kernel32.LoadLibraryA
00BCAC A3 1413A86F	MOV     [6FA81314],EAX

You may be tempted to just start packing bytes into the values like this ...

{0x00BCA0,0x506830BD,FT_NON},

First off, the bytes must be reversed...

{0x00BCA0,0xBD306850,FT_NON},

This would be ok but now you can't apply a fixup to the address 6fa7bd30. This will work fine if the dll gets loaded at the same address but we want our code to work even if the dll is loaded somewhere else.
So ...

{0x00BCA0,0x00006850,FT_NON},	// pad the value with zero in the address part.
{0x00BCA2,0x6FA7BD30,FT_FIX},   // set the offset to the address part and use FT_FIX.


Now the call...

{0x00BCA6,0x000015FF,FT_NON},	// pad the value with zero in the address part.
{0x00BCA8,0x6FA7C040,FT_FIX},   // set the offset to the address part and use FT_FIX.

It's a fixed call so we use FT_FIX. But you can also use function names in the value...

{0x00BCA6,0x000015FF,FT_NON},	// pad the value with zero in the address part.
{0x00BCA8,LoadLibrary,FT_NON},  // set the offset to the address part and use FT_NON!

Here we used FT_NON because the linker uses the import address for LoadLibrary in this dll not in the d2 dll we are modifying. This address is automatically fixedup when our dll is loaded. You will use FT_NON anytime you have a fixed reference into your own code.



CALLING YOUR C FUNCTIONS
-------------------------

Most of the code edits you have will be a patch to call your own c functions, replacing all or some of the code in a d2 function.

When replacing an entire function, prototype your C function to match. Then patch the start of the d2 function with a jmp to your function. On return, your function will return to the original caller.

Here's the start of a d2 function ...

6FAFFFCD   90               NOP
6FAFFFCE   90               NOP
6FAFFFCF   90               NOP
6FAFFFD0 > 81EC D4000000    SUB     ESP,0D4                          ; UpdateStaminaBar
6FAFFFD6   53               PUSH    EBX
6FAFFFD7   55               PUSH    EBP
6FAFFFD8   56               PUSH    ESI
6FAFFFD9   57               PUSH    EDI
6FAFFFDA   E8 F1830200      CALL    d2client.6FB283D0                ; GetClient()

...

6FB0019F   5F               POP     EDI
6FB001A0   5E               POP     ESI
6FB001A1   5D               POP     EBP
6FB001A2   5B               POP     EBX
6FB001A3   81C4 D4000000    ADD     ESP,0D4
6FB001A9   C3               RETN


The function is void (). It has no params and no return. So we make our own function ...

void UpdateStaminaBar()
{
    do stuff ...
}

And insert a jmp to our function at the very begining...

6FAFFFD0 > E9 FB830200      JMP     _UpdateStaminaBar                ; UpdateStaminaBar
6FAFFFD5   90               NOP
6FAFFFD6   53               PUSH    EBX


Our code-edit will look like this...

{0x005FCD,0xE9909090,FT_NON},
{0x005FD1,UpdateStaminaBar,FT_REL},

You may have noticed, We didn't pad the address part with zero this time. I took advantage of the NOP's and backed up 3 bytes to make the edit line up on the address.
We also used FT_REL. E9 is a relative jmp so we needed the difference between the current address and the function address for the value.

There is no need to cleanup the bytes following the jmp. Our function will never return here so the code will never be executed.

A lot of the time you don't want to replace the whole function. You may just need to call your fuction when the d2 functio is called. The best choice is to find a call in the function and change it to you function. In this case we have the perfect place. We replace the call to getClient with our function..

{0x005FDB,MyFunction,FT_REL},

Then the function can return the replaced function when finished...

LPVOID MyFunction()
{
    do stuff ...
    return GetClient();
}

For difficult changes where there is not enough room for a simple edit and no good places for calls, you can use a "NAKED" function. NAKED functions have no calling conventions. They save no registers and leave the stack as is except for the return address.
We will use a relative call to call our function...

6FAFFFD0 > E8 FB830200      CALL     _UpdateStaminaBar                ; UpdateStaminaBar
6FAFFFD5   90               NOP
6FAFFFD6   53               PUSH    EBX
6FAFFFD7   55               PUSH    EBP
6FAFFFD8   56               PUSH    ESI


{0x005FCD,0xE8909090,FT_NON},
{0x005FD1,UpdateStaminaBar,FT_REL},
{0x005FD5,0x56555390,FT_NON},	// clean up the return area

In this case we must cleanup the return area, our NAKED function will return here...

static DWORD fret; // tmp storage for the NAKED return address.

NAKED UpdateStaminaBar()
{
    __asm {
	pop [fret]	; save return address for later
        push xxx	; save regs/push args
	call MyTest	; call our C function or just check a value
        test eax,eax    ;
        pop xxx		; restore regs
        jne ret1        ;
        ret             ; our test failed, bypass d2 function, return to original caller.
ret1:
        sub esp,0d4	; we must duplicate the code we replaced before we return!
        push [fret]     ; push the local return address back on the stack
        ret		; return to d2 function as if we were never here ;-)
    }
}

Any registers you change will be changed when you return so be sure it's what you want.
There are many variations on this idea. Check the samples for some other uses.


===========================================================



CALLING D2 FUNCTIONS
---------------------

Above we called the d2 function GetClient(). It is called just like any normal C function because it has been exported and defined in the header files that come with the SDK.

There are many exports already defined in the headers. Look through them to see if the function you want is there.

If not, you can access the address of any export with its generic name, ie; D2Common_10001.
To get any other non-exported address use the "base" of the dll and add your offset, ie; D2CommonBase + 0x005FD5.

If you have/find function prototypes for D2 functions that are not in the headers, please email me and I will add them to the SDK. If you have structures for d2 data (ptGame,player etc) these would be welcome also.

My email is webmail@stx.rr.com



USING THE INI FILE
-------------------

The D2Mod system is setup to use an ini file to allow the user/mod maker to specify which dlls to load and what settings to use. In order for everything to function correctly, any settings you need to have for your mod dll must be stored in the d2mod system ini file.
You have no way to know what the name of this ini file will be. It is left to the user/mod maker to name the file as they wish.
To deal with this feature you must use the name passed to the Init function to retreive your settings.
In your readme, place the lines to be copied into the d2mod ini...

;[D2MOD]
MyMod=mymod.dll

[MyMod]
setting=x,y,z
...

Then in your Init function you can read your settings from the [MyMod] section.
You may want to use your own ini file but that will cause problems between different mods that use your dll, so please use the name passed.

