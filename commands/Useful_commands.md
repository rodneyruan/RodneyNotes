### Generate and apply patch with git
```
git -C arris-source_private fetch ssh://ttmgerrit.arrisi.com:29418/TTM/puma7/arris-source_private refs/changes/33/10733/3
#Create radvision patch from the diff of baseline code and latest changes
git -C arris-source_private diff FETCH_HEAD -- arm/thirdparty/SIP/ > radvision.patch

git apply  arm/thirdparty/SIP/radvision.patch
```
