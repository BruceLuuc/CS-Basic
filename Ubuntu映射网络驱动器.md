
##### 1.`sudo apt-get install cifs-utils`
##### 2.`sudo gedit /etc/nsswitch.conf`

�ҵ�
`hosts: files mdns4_minimal [NOTFOUND=return] dns`
���`wins`
`hosts: files mdns4_minimal [NOTFOUND=return] wins dns`

##### 3.����һ��У���ļ�
    
`gedit ~/.smbcredentials`
��������
`username=Զ��������`
`password=Զ�̵�¼����`
    
##### 4.`sudo gedit /etc/fstab`

�����һ�����
`//10.1.74.174/luwenwen /home/ww/Desktop/10.1.74.174 cifs ��credential=/home/ww/.smbcredentials,vers=1.0,iocharset=utf8,gid=1000,uid=1000,file_mode=0777,dir_mode=0777 00`
 ע:`10.1.74.174/luwenwen`Ϊ�ҵ�Զ�̱��������   
 ע:`/home/ww/Desktop/10.1.74.174`Ϊ�ڱ������潨������Ϊ`10.1.74.174`�ļ��У�����ʶ��
 ע:�ҵ�������`vers=1.0 `�����汾ʧ�ܡ�

##### 5.����������
`sudo mount -a`



