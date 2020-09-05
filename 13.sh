#!/usr/bin/env bash

regedit /E diablo_HKLM.reg 'HKEY_LOCAL_MACHINE\Software\Blizzard Entertainment\Diablo II\'
regedit /E diablo_HKCU.reg 'HKEY_CURRENT_USER\Software\Blizzard Entertainment\Diablo II\'
# DIABLO_SAVE="$( wine cmd <<< exit | tail -1 | tr -d '>' | sed 's|\\|\\\\\\\\|g' )\\\\\\\\Save"
# iconv -f utf-16 -t utf-8 < diablo.reg | sed 's|^"Save.Path"=.*$|"Save Path"="'"${DIABLO_SAVE}"'"|g' > diablo_new.reg
# regedit /C diablo_new.reg

mkdir -p data/global/excel
#for i in data/global/excel/*.txt
#  do unix2dos "${i}"
#done

wine 'c:\Program Files (x86)\Diablo II\Game.exe' -w -direct -txt

rm -f data/global/excel/*.bin data/global/excel/*.bak
# regedit /C diablo.reg
