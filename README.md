# 2021年ロボットシステム学課題
## 動作環境
|  CPU |  Raspberry Pi 4 8GB  |
| ---- | ---- |
|  OS  |  Ubuntu20.4  |
## 使用部品
|  7セグメントLED  |Ｃ－５５１ＳＲＤ    |
| ---- | ---- |
|  圧電ブザー |  TMB12A05 |
|  抵抗 |  220Ω  |
## 回路図
![image](https://user-images.githubusercontent.com/94948436/146022971-d9a841a8-a800-49ea-894b-79c63ed4cc0a.png)
![iOS の画像 (21)](https://user-images.githubusercontent.com/94948436/146133229-ae4c0d7e-5f2c-4c51-8299-325d622be748.jpg)

## インストール方法
以下の順番でコマンドを実行しクローンする  
 `$ git clone https://github.com/Sanatbasu/device_driver.git`  
 `$ cd LED_device_driver`    
 
## 動作方法
以下の順番で実行し、書き込み権限を付与する    
 `$ make`     
`$ sudo insmod myled.ko`    
`$ sudo chmod 666 /dev/myled0`    

+ 好きな1~9までの数numberを入力    
`$ echo <number> > /dev/myled0`    
するとその数字からカウントダウンが始まり、時間になるとブザーが鳴ってくれる   
+ 0を入力    
`$ echo 0 > /dev/myled0`       
「HELLO」を表示してくれる
## アンインストール方法
以下の順番で実行    
 `$ sudo rmmod myled`    
 `$ make clean`
##  実行動画
https://www.youtube.com/watch?v=aylZqpt0Ay0

https://www.youtube.com/watch?v=mnDU9J7yVrc
## ライセンス
[GNU General Public License v3.0](https://github.com/Sanatbasu/device_driver/blob/main/COPYING)
