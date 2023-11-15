## Table of Contents

- [Section XB7](#xb7)
  -  [Create a XB7 Worksapce](#create-xb7-worksapce)
  -  [Build XB7 Private Image](#build-xb7-private-image)
  - [Build Comcast Image](#build-comcast-image)
- [Section XB6](#section-xb6)
  -  [Create a XB6 Workspace](#create-a-xb6-workspace)
- [Common Tips](#common-tips)
  -  [repo start](#repo-start)
  -  [repo upload](#repo-upload)
  -  [UCF Format](#ucf-format)
  -  [Zilker Problem](#zilker-problem)
  -  [Cherry-pick Arris Private Changes](#cherry-pick-arris-private-changes)
## XB7
### Create XB7 Worksapce
XB7 5.15 Workspace
```
repo init -u ssh://gerrit.teamccp.com:29418/rdk/yocto_oe/manifests/arris-intel-manifest -b 23Q4_sprint -m arrisxb7-sdk72x.xml --repo-url=ssh://gerrit.teamccp.com:29418/rdk/tools/git-repo --repo-branch master --no-repo-verify -g all
JOB_NAME=local  repo sync --verify  -j 24
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/meta-arris-intel-gw-private -b xb7 meta-arris-intel-gw-private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/puma7/arris-source_private -b xb7 arris-source_private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-secure-login -b xb7 arris-secure-login
mkdir arris-iot && cd arris-iot && git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-iot -b master arris-iot && cd ..
```
XB7 4.9 workspace
```
repo init -u ssh://gerrit.teamccp.com:29418/rdk/yocto_oe/manifests/arris-intel-manifest -b 23Q4_sprint -m arrisxb7-sdk72x-4.9.xml --repo-url=ssh://gerrit.teamccp.com:29418/rdk/tools/git-repo --repo-branch master --no-repo-verify -g all
JOB_NAME=local  repo sync --verify  -j 24
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/meta-arris-intel-gw-private -b xb7 meta-arris-intel-gw-private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/puma7/arris-source_private -b xb7 arris-source_private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-secure-login -b xb7 arris-secure-login
mkdir arris-iot && cd arris-iot && git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-iot -b master arris-iot && cd ..
```

#### Roll back SDK7.3.5
```
cd arris-source_private
git fetch http://rruan@ttmgerrit.arrisi.com/a/TTM/puma7/arris-source_private refs/changes/52/9952/2 && git cherry-pick FETCH_HEAD
cd ..
```

### Build XB7 Private Image
```
MACHINE=arrisxb7-sdk72x
source  meta-arris-intel-gw-private/setup-environment pc20
cd build-arrisxb7atom-sdk72x-pc20; bitbake comcast-broadband-dev-image 
cd ../build-arrisxb7arm-sdk72x-pc20; bitbake comcast-broadband-dev-image 
```
```
MACHINE=arrisxb7-sdk72x
source  meta-arris-intel-gw-private/setup-environment sipv6
cd build-arrisxb7atom-sdk72x-sipv6; bitbake comcast-broadband-dev-image 
cd ../build-arrisxb7arm-sdk72x-sipv6; bitbake comcast-broadband-dev-image 
```
```
MACHINE=arrisxb7-sdk72x
source  meta-arris-intel-gw-private/setup-environment ncs
cd build-arrisxb7atom-sdk72x-ncs; bitbake comcast-broadband-dev-image 
cd ../build-arrisxb7arm-sdk72x-ncs; bitbake comcast-broadband-dev-image 
```
####  build  SIPV6 and NCS  image
```
打开这两个配置文件，加入下面这行， 记得 "sipv6"前面要留空格,否则会和其他参数粘在一起, 而且要加在voice stack name 那一行 前面
DISTRO_FEATURES_append = " sipv6 " 
XB7

./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-arm/conf/machine/arrisxb7arm-sdk72x.conf
./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-atom/conf/machine/arrisxb7atom-sdk72x.conf

XB6
./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-arm/conf/machine/arrisxb6p2arm-sdk72x.conf
./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-atom/conf/machine/arrisxb6p2atom-sdk72x.conf
```

#### 用这个sed 命令直接可以插入一行：

```
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-arm/conf/machine/arrisxb7arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"'  ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-atom/conf/machine/arrisxb7atom-sdk72x.conf -i

sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" pc15 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-arm/conf/machine/arrisxb7arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" pc15 \"'  ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb7-atom/conf/machine/arrisxb7atom-sdk72x.conf -i
```
#### Build Comcast Image
```
For Comcast image:
MACHINE=arrisxb7atom-sdk72x source meta-rdk/setup-environment 
bitbake comcast-broadband-dev-image 

cd .. 
mkdir -p tmp/deploy/images ; cd tmp/deploy/images 

ln -s ../../../../build-arrisxb7atom-sdk72x/tmp/deploy/images/arrisxb7atom-sdk72x/ arrisxb7atom-sdk72x 

cd ../../.. 
MACHINE=arrisxb7arm-sdk72x source meta-rdk/setup-environment 
bitbake comcast-broadband-dev-image 

```

## Section XB6

#### Create a XB6 workspace
XB6 5.15 Workspace
```
repo init -u ssh://gerrit.teamccp.com:29418/rdk/yocto_oe/manifests/arris-intel-manifest -b 23Q4_sprint -m arrisxb6p2-sdk72x.xml --repo-url=ssh://gerrit.teamccp.com:29418/rdk/tools/git-repo --repo-branch stable --no-repo-verify
JOB_NAME=local  repo sync --verify  -j 24

git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/meta-arris-intel-gw-private -b xb7 meta-arris-intel-gw-private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/puma7/arris-source_private -b xb7 arris-source_private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-secure-login -b xb7 arris-secure-login
mkdir arris-iot && cd arris-iot && git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-iot -b master arris-iot && cd ..

ln -s /export/rruan/yocto-downloads/ downloads
```
XB6 4.9 workspace
```
repo init -u ssh://gerrit.teamccp.com:29418/rdk/yocto_oe/manifests/arris-intel-manifest -b 23Q4_sprint -m arrisxb6p2-sdk72x-4.9.xml --repo-url=ssh://gerrit.teamccp.com:29418/rdk/tools/git-repo --repo-branch stable --no-repo-verify
JOB_NAME=local  repo sync --verify  -j 24

git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/meta-arris-intel-gw-private -b xb7 meta-arris-intel-gw-private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/puma7/arris-source_private -b xb7 arris-source_private
git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-secure-login -b xb7 arris-secure-login
mkdir arris-iot && cd arris-iot && git clone ssh://rruan@ttmgerrit.arrisi.com:29418/TTM/arris-iot -b master arris-iot && cd ..

ln -s /export/rruan/yocto-downloads/ downloads
```

#### Build image 
```
MACHINE=arrisxb6p2-sdk72x; source meta-arris-intel-gw-private/setup-environment pc20
 
cd build-arrisxb6p2atom-sdk72x-pc20; bitbake comcast-broadband-dev-image 
cd build-arrisxb6p2arm-sdk72x-pc20; bitbake comcast-broadband-dev-image 

MACHINE=arrisxb6p2-sdk72x; source meta-arris-intel-gw-private/setup-environment sipv6
cd build-arrisxb6p2atom-sdk72x-sipv6; bitbake comcast-broadband-dev-image 
cd build-arrisxb6p2arm-sdk72x-sipv6; bitbake comcast-broadband-dev-image 
```
#### Build SIPv6 or NCS
```

sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-arm/conf/machine/arrisxb6p2arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" sipv6 \"'  ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-atom/conf/machine/arrisxb6p2atom-sdk72x.conf -i

sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" pc15 \"' ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-arm/conf/machine/arrisxb6p2arm-sdk72x.conf -i
sed -e '/enable_aqm/aDISTRO_FEATURES_append = \" pc15 \"'  ./meta-rdk-oem-arris-intel-gw-xb6/meta-arrisxb6-atom/conf/machine/arrisxb6p2atom-sdk72x.conf -i

```


### Edit IPK version for Comcast build
```
cd meta-rdk-oem-arris-intel-gw-xb6
meta-arrisxb7-common/conf/arris-config.inc
meta-arrisxb7-common/conf/ipk_versions.txt
meta-arrisxb6-common/conf/arris-config.inc
meta-arrisxb6-common/conf/ipk_versions.txt
```
### Commit message
```
CMXB7-5101 MTA did not obtain IP during WAN mode transition from EWAN to Docsis

Reason for change: CMXB7-xxxx MTA did not obtain IP during WAN mode transition from EWAN to Docsis
Test Procedure: 

Verified that Basic call worked fine.
Risks: None

Signed-off-by: Rodney Ruan <Rodney.Ruan@commscope.com>
```

### Upload IPK files to artifactory
#### Website
```
https://partners.artifactory.comcast.com/ui/packages
Select Deploy, then select Deploy as Maven Artifacts
```
#### XB7  
Find the artifacts: cscope_xb7/components/dunfell-ipks/cscope-ipk-sip   
Group ID   
```
components.dunfell-ipks
```
Artifact ID for PC20 
```
cscope-ipk-pc20
```
Artifact ID for SIPV6 
```
cscope-ipk-sip
```
Artifact ID for NCS 
```
cscope-ipk-ncs
```

#### XB6
Find the artifacts: arris_xb6/components/dunfell-ipks/cscope-ipk-sip   
Group ID   
```
components.dunfell-ipks
```
Artifact ID for PC20 
```
arris-ipk-sdk7.2
```
Artifact ID for SIPV6 
```
arris-ipk-sip-sdk7.2
```
Artifact ID for NCS 
```
arris-ipk-ncs-sdk7.2
```



### Build Images on Jenkins
```
6 在jenkins build image
https://jenkins.ccp.xcal.tv/jenkins/job/ARRISXB6-Yocto-Build/
https://jenkins.ccp.xcal.tv/jenkins/job/COMMSCOPEXB7-Yocto-Build
GERRIT_PATCH_SET 这里选择patchset
rdk/yocto_oe/layers/meta-rdk-oem-arris-intel-gw-xb6-sdk7.2x 766631/2

rdk/yocto_oe/layers/meta-rdk-oem-arris-intel-gw-xb6-sdk7.2x 793278/2
rdk/yocto_oe/layers/meta-rdk-oem-arris-intel-gw-xb6-sdk7.2x 762963/1
 signed的load，在jenkins上看不到，要去下面的网站找：
https://rdkportal.ccp.xcal.tv/builds?image_name=TG4482SV6_DEV_6.0_p1b_20230516073352sdy*
```
## Common Tips
### repo start 
```
 repo start contrib/bp-rruan335/INTCS-620 meta-rdk-oem-arris-intel-gw-xb6
```
### repo upload 
/export/rruan/repo upload --cbr meta-rdk-oem-arris-intel-gw-xb6
```
If you see AttributeError: Values instance has no attribute 'validate_certs'
Modify this python script:
vi .repo/repo/subcmds/upload.py     
379 行
         branch.UploadForReview(people,
                                auto_topic=opt.auto_topic,
                                draft=opt.draft,
                                private=opt.private,
                                notify=None if opt.notify else 'NONE',
                                wip=opt.wip,
                                dest_branch=destination,
                                validate_certs=True, <-----改成True
                                push_options=opt.push_options)

```
### UCF Format
```
INTCS-XXX [5.15][Field] One way audio blah blah

Reason for change: INTCS-XXX [5.15][Field] One way audio blah blah .
Test Procedure:
Verified that 
Risks: None
Signed-off-by: Rodney Ruan <Rodney.Ruan@commscope.com>
```
### Cherry-pick Arris Private Changes
```
cd arris-source_private

 git cherry-pick 4dcbedf24b60ae1aabd3f18f54ffa5fb8536f450
 git cherry-pick 027d6f46c48b05f0446d0736261cef2ea05ff614
cd ..
```

### Zilker Problem

If you encounter compile problem with Zilker, cherry pick this patch   
https://gerrit.teamccp.com/#/c/760929/
```
cd meta-rdk-comcast-broadband
git fetch https://bp-rruan335@gerrit.teamccp.com/a/rdk/yocto_oe/layers/meta-rdk-comcast-broadband refs/changes/29/760929/4 && git cherry-pick FETCH_HEAD
```
