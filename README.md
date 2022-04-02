# pescan
对exe文件是否有病毒的扫描小工具
这是一个扫描PE(EXE)文件是否有病毒的工具程序
实现思路：
获取有病毒的PE文件和正常文件样本
用read.sh读取两个文件夹下的文件名并转存
hash.c hash.h main.c c语言实现了一个哈希表(这是为了和clamav(一种linux下病毒扫描工作)源码结合),仅做工具可以忽略。
通过2-gram滑动窗口提取数据，每个文件最高频的20个特征转换成int存储到hash表中作为key值，对病毒文件夹和正常文件夹各自提取最高频的二十个特征，作为特征向量，如data.txt所示，前二十列为向量，最后一列为标签，1为有病毒，0为正常文件。
BP神经网络与KNN结合训练，构建模型，导出参数到scanpe.c(使用knn和BP神经网络结合预测文件)
test.py 由tkinter实现，只要有python环境即可运行。
![image](https://user-images.githubusercontent.com/79775390/161360822-fd5ecf03-1510-4dfc-90ac-930fb074b074.png)

剥离出来使用即可，请在输入框中输入EXE扫描文件的路径（适用于所有linux发行版)，点击mode3运行即可。

![image](https://user-images.githubusercontent.com/79775390/161360747-a7a6e99e-e95c-4a37-8eb8-fa0106078f23.png)
