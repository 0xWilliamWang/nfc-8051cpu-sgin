# 简介
1. 本代码目标运行平台8051系列CPU
2. 使用`keilc51`进行编译和仿真
3. 本项目使用secp256r1进行了验证，验证方法是：
   1. 在仿真平台中对字符串`hello`的sha256哈希值进行签名
   2. 在keil的命令窗口保存签名值和公钥，使用公钥和签名值到外部系统进行验证
# keilc51保存内存中的值（变量）
1. save signatureR.txt X:0x000004,X:0x000023
2. save signatureS.txt X:0x000024,X:0x000043
3. save publicX.txt X:0x000044,X:0x000063
4. save publicY.txt X:0x000064,X:0x000083

# 参考
1. 移植的原库[nano-ecc](https://github.com/iSECPartners/nano-ecc)
2. JavaScript`secp256r1`签名库[ecdsa-secp256r1](https://github.com/forevertz/ecdsa-secp256r1)