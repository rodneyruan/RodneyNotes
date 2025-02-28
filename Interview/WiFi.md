### WiFi6 WiFi6E WiFi7
| **Aspect**           | **Wi-Fi 6**    | **Wi-Fi 6E**   | **Wi-Fi 7**    |
|-----------------------|----------------|----------------|----------------|
| **Bands**            | 2.4, 5 GHz     | 2.4, 5, 6 GHz  | 2.4, 5, 6 GHz  |
| **Max Speed**        | 9.6 Gbps       | 9.6 Gbps       | 46 Gbps        |
| **Channel Width**    | 160 MHz        | 160 MHz        | 320 MHz        |
| **QAM**              | 1024           | 1024           | 4096           |
| **MLO**              | No             | No             | Yes            |
| **Spatial Streams**  | 8              | 8              | 16             |
| **Primary Gain**     | Efficiency     | Less interference | Speed + Latency |

### 4-way-handshake
```
AP发起

PTK 单播用的key
GTK 组播广播用的key
PSK 俗称的WIFI 密码生成的
PMK 由PSK生成
PTK 是由 PMK, A_nonce 和S_nonce，双方的MAC地址 经一个伪随机函数生成
MIC 是PTK的前16位的哈希， 校验用的
GTK AP生成，deliver 给STA， 由PTK加密

消息1 AP生成A nonce 发给STA
消息2 STA生成S nonce, 再生成PTK， 把校验值MIC 发给STA
消息3 AP deliver 校验 MIC，用PTK 加密 GTK 发给STA
消息4 STA 确认

破解方式： 抓到4个包，就可以offline 的用dictionary 暴力破解， 这个是WPA的弱电
```
