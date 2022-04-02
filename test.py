from tkinter import *
import os
import time
class A:
    def __init__(self, master=None):
        self.root = master
        self.root.geometry('800x600+200+200')
        self.root.title('clamav助手')
        self.frm1 = Frame(self.root)
        self.frm2 = Frame(self.root)
        self.frm3 = Frame(self.root)
        
        self.createpage()
    def clearinfo(self):
        self.text.delete(1.0,END)
    def update(self):
        os.system('freshclam')
        time.sleep(1)
        self.text.insert(INSERT,'update success')
    def mode1(self):
        self.text.delete(1.0,END)
        s=self.entry.get()
        print(s)
        ss="clamscan -r "+s
        print(ss)
        with open('/home/liyilin/output.txt','w') as outfile:
            outfile.write(os.popen(ss).read())
        with open('/home/liyilin/output.txt','r',encoding='utf-8') as fin:
            txt=fin.readlines()
        strout=("".join(txt))
        print(strout)
	 
        self.text.insert(INSERT,strout)
    def mode2(self):
        self.text.delete(1.0,END)
        s=self.entry.get()
        print(s)
        ss="clamscan -r "+s
        print(ss)
        with open('/home/liyilin/output.txt','w') as outfile:
            outfile.write(os.popen(ss).read())
        with open('/home/liyilin/output.txt','r',encoding='utf-8') as fin:
            txt=fin.readlines()
        strout=("".join(txt))
        print(strout)
	 
        self.text.insert(INSERT,strout)
    def mode3(self):
        self.text.delete(1.0,END)
        s=self.entry.get()
        ss="./sum "+s
        print(ss)
        with open('/home/liyilin/output.txt','w') as outfile:
            outfile.write(os.popen(ss).read())
        with open('/home/liyilin/output.txt','r',encoding='utf-8') as fin:
            txt=fin.readlines()
        strout=("".join(txt))

        self.text.insert(INSERT,strout)
    def help(self):
        self.text.delete(1.0,END)
        self.text.insert(INSERT,'The following is the mode description\n\n')
        self.text.insert(INSERT,'Mode 1 calls ClamAV to scan folders\n\n')
        self.text.insert(INSERT,'Mode 2 calls ClamAV to scan single file\n\n')
        self.text.insert(INSERT,'Mode 3 calls independent code to scan single file\n\n')
        self.text.insert(INSERT,'Please enter the path of the file or folder\n\n')
        self.text.insert(INSERT,'Use update button to update virus database\n')
    def createpage(self):

        self.frm1.config(bg='#FFFFE0', height=500, width=600)
        #Label(self.frm1, text='frm1').place(in_=self.frm1, anchor=NW)
        self.frm1.place(x=180, y=50)
        self.frm2.config(bg='#F0FFF0', height=500, width=150)
        #Label(self.frm2, text='frm2').place(anchor=NW)
        self.frm2.place(x=20, y=50)
        self.frm3.config(bg='#87CEEB', height=40, width=760)
       # Label(self.frm3, text='frm3').place(in_=self.frm3, anchor=NW)
        self.frm3.place(x=20, y=5)
        # frm3下的Label
        Label(self.frm3, text='点击按钮以实现对应功能',
              fg='black', font='Verdana 10 bold').place(x=300, y=10)
        # frm2下的Button
        self.entry=Entry(self.frm1,width=40)
        self.entry.place(x=120,y=20)
        Button(self.frm1, text='update',command=self.update).place(x=500, y=15, width=60)
        Button(self.frm2, text='clear',command=self.clearinfo).place(x=20, y=20, width=100)
        Button(self.frm2, text='mode1',command=self.mode1).place(x=20, y=120, width=100)
        Button(self.frm2, text='mode2',command=self.mode2).place(x=20, y=220, width=100)
        Button(self.frm2, text='mode3',command=self.mode3).place(x=20, y=320, width=100)
        Button(self.frm2, text='help',command=self.help).place(x=20, y=420, width=100)
        # frm1下的控件
        self.text=Text(self.frm1,width=60,height=25)
        self.text.place(x=50,y=68)
  
if __name__ == '__main__':
    root = Tk()
    A(root)
    mainloop()
