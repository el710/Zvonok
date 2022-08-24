del *.~*
del *.obj
del *.tds

mkdir ..\Zvonok
copy Zvonok.exe ..\Zvonok\Zvonok.exe
cd default
copy *.* ..\..\Zvonok\*.*