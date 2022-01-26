#!/bin/sh

plugins=("TapBootstrap" "TapCommon" "TapDB" "TapLogin" "TapMoment" "XDCommon" "XDAccount" "XDAnti")

function DeleteBuild()
{
    rm -rf Plugins/$1/Binaries
    rm -rf Plugins/$1/Intermediate
}

for ((i=0;i<${#plugins[@]};i++));do
    DeleteBuild ${plugins[$i]}
done  

#zip -q -r XDSDK-UE4_$1.zip Plugins/