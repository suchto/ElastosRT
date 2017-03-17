1. enter the build environment
cd Elastos5/Setup
Elastos5/Setup$ source SetEnv.sh gcc_devtools

2. build CAR tools
Elastos5/Sources$ emake 
Elastos5/Sources$ pd @

3. build result
~/workspace4Elastos/Elastos5/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ ls
CInfoReader  Cls2C  carc  carcode  dbg_info  libz.so  lubc  lube  package 

4. release version or debug version
$ rls
It is an alias of  --> chv rls
$ dbg
It is an alias of  --> chv dbg

5. use your new CAR tools
copy your build result to Elastos5/Build/Tools
from Elastos5/Targets/rdk/x86.gnu.linux.devtools.rls/bin
