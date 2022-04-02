import torch
import torch.nn.functional as F
from torch.autograd import Variable
import torch.utils.data as Data
import numpy as np
import math
class BPNeuralNetwork(torch.nn.Module):
    def __init__(self):
        super(BPNeuralNetwork, self).__init__()

        self.h1 = torch.nn.Linear(20, 30)
        self.h2 = torch.nn.Linear(30, 10)
        self.o = torch.nn.Linear(10, 1)

    def forward(self, x):
        x = self.h1(x)
        x = F.relu(x)
        x = self.h2(x)
        x = F.relu(x)
        x = self.o(x)
      #  x = x.squeeze(-1)
        return x
def Normalize(data):

    m = np.mean(data)

    mx = max(data)

    mn = min(data)

    return [(float(i) - m) / (mx - mn) for i in data]

if __name__ == "__main__":

    tr_input_x=[]
    tr_input_y=[]
    pr_input_x=[]
    pr_input_y=[]
    with open('bad.txt', 'r') as f:
        my_data = f.readlines()  # txt中所有字符串读入data，得到的是一个list
        # 对list中的数据做分隔和类型转换
        for line in my_data:
            line_data = line.split(' ')
            length=len(line_data)
            print(line_data[length-1])
            tr_input_y1=[]
            tr_input_y1.append((int(line_data[length-1])))
            tr_input_y.append(tr_input_y1)
            line_datax=line_data[0:length-1]
            print(line_datax)
            new_numbers = []

            for n in line_datax:

                new_numbers.append(int(n))

            print(new_numbers)
            tr_input_x.append(new_numbers)
           # numbers_float = map(float, line_data)  # 转化为浮点数
      #  print(my_data[1].split(' '))
    print(len(tr_input_x))
    print(len(tr_input_x[0]))
    print(len(tr_input_y))
    with open('predict.txt', 'r') as f:
        my_data = f.readlines()  # txt中所有字符串读入data，得到的是一个list
        # 对list中的数据做分隔和类型转换
        for line in my_data:
            line_data = line.split(' ')
            length = len(line_data)
            print(line_data[length - 1])
            pre_input_y1 = []
            pre_input_y1.append((int(line_data[length - 1])))
            pr_input_y.append(pre_input_y1)
            line_datax = line_data[0:length - 1]
            print(line_datax)
            new_numbers = []

            for n in line_datax:
                new_numbers.append(int(n))

            print(new_numbers)
            pr_input_x.append(new_numbers)
    print(pr_input_x)
    tr_input_xnew=[]
    pr_input_xnew=[]
    for x in tr_input_x:
        a=Normalize(x)
        tr_input_xnew.append(a)
    for y in pr_input_x:
        b=Normalize(y)
        pr_input_xnew.append(b)
    model = BPNeuralNetwork()
    learning_rate = 1e-5
    max_epoches = 500
    print(tr_input_xnew)
    train_x = torch.FloatTensor(tr_input_x)
    train_y = torch.FloatTensor(tr_input_y)
    test_x = torch.FloatTensor(pr_input_x)

    torch_dataset = Data.TensorDataset(train_x,train_y)
    loader = Data.DataLoader(dataset=torch_dataset, batch_size=10, shuffle=True)

    optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
    loss_function = torch.nn.MSELoss()
    num=0
    for epoch in range(max_epoches):
        num=num+1
        print("正在进行第" + str(num) + "轮训练")
        for i in range(len(train_x)):
            instance = Variable(train_x[i])
            label = Variable(train_y[i])

            output = model.forward(instance)
            loss = loss_function(output, label)
            #print(loss)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

    test_x = Variable(test_x)
    ans=model.forward(test_x)
    i=0
    right=0
    for x in ans:
        temlabel=0
        print(x.item())
        if(x.item()>0.5):
            temlabel=1
        print(pr_input_y[i])
        if(temlabel==pr_input_y[i][0]):
            right=right+1
        i=i+1
    print("经过500轮训练，正确率为：")
    print(right/len(pr_input_y))

    params = list(model.parameters())
    np.set_printoptions(suppress=True)
    print(params)