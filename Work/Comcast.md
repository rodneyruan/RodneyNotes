### Create workspace
```
repo init -u ssh://gerrit.teamccp.com:29418/rdk/yocto_oe/manifests/arris-intel-manifest -b 23Q4_sprint -m arrisxb7-sdk72x.xml --repo-url=ssh://gerrit.teamccp.com:29418/rdk/tools/git-repo --repo-branch master --no-repo-verify -g all
repo sync --verify 

git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/meta-arris-intel-gw-private -b xb7 meta-arris-intel-gw-private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/puma7/arris-source_private -b shared/xb7_734 arris-source_private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-secure-login -b xb7 arris-secure-login
mkdir arris-iot && cd arris-iot && git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-iot -b master arris-iot && cd ..

cd arris-source_private 这个是为了roll back SDK7.3.5
git fetch http://rruan@ttmgerrit.arrisi.com/a/TTM/puma7/arris-source_private refs/changes/52/9952/2 && git cherry-pick FETCH_HEAD

 /export/rruan/repo start contrib/bp-rruan335/INTCS-620 meta-rdk-oem-arris-intel-gw-xb6
```
###  build  SIPV6  image
```
打开这两个配置文件，加入下面这行， 记得 "sipv6"前面要留空格,否则会和其他参数粘在一起, 而且要加在voice stack name 那一行 前面
DISTRO_FEATURES_append = " sipv6 " 
XB7

./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-arm/conf/machine/arrisxb7arm-sdk72x.conf
./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-atom/conf/machine/arrisxb7atom-sdk72x.conf

XB6
./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-arm/conf/machine/arrisxb6p2arm-sdk72x.conf
./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-atom/conf/machine/arrisxb6p2atom-sdk72x.conf

用这个sed 命令直接可以插入一行：
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-arm/conf/machine/arrisxb7arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-atom/conf/machine/arrisxb7atom-sdk72x.conf -i

sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-arm/conf/machine/arrisxb6p2arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-atom/conf/machine/arrisxb6p2atom-sdk72x.conf -i

sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" pc15 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-arm/conf/machine/arrisxb6p2arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" pc15 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-atom/conf/machine/arrisxb6p2atom-sdk72x.conf -i
```
