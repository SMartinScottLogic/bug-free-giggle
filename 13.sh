#!/usr/bin/env bash

mkdir -p data/global/excel
wine 'c:\Program Files (x86)\Diablo II\Game.exe' -w -direct -txt

rm -f data/global/excel/*.bin data/global/excel/*.bak
