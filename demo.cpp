#include<iostream>
#include<stdlib.h>
#include<time.h> 
#include<graphics.h>
#include<mmsystem.h>
#include<windows.h>
#include<vector>
#include<ege/sys_edit.h>
#include<iostream>
using namespace std;

static int days = 1;
					//����	
void goBegin();

void train(int num);

void rest(int num);

void finishOneDay();

void warning(char* str);

void goTitle();

void goManage();

void goControl();

void goChoose();

void goSetting();

void goRules();

void changeRecruitList();

void showMember(int num);

void printAvatar();

void gohe();

void gote();

void gobe();

static double allProfit = 5000;

//������ 
class Creature{
    protected:
      char* name;
      double height;
      double weight;
    public:
      Creature();
      Creature(char* name,int height,int weight);
};

Creature::Creature()
{
  this->name = 0;
  this->height = 0;
  this->weight = 0;
}

Creature::Creature(char* name,int height,int weight)
{
  this->name = name;
  this->height = height;
  this->weight = weight;
}



//��������
class Fantancy
{
    protected:
      float DIF;
      int value;
      float SANDam;
      PIMAGE avatar;
      char * des;
      float tempDIF;
    public:
      Fantancy();
      Fantancy(float DIF,int value,float SANdam,char* image,char* des);
      float getDif();
      float getSANDam();
      int getValue();
      char* getDes(); 
      PIMAGE getImage();
      void setImage(char* address);
};

Fantancy::Fantancy()
{
  this->DIF = 0.0;
  this->value = 0;
  this->SANDam = 0;
}

Fantancy::Fantancy(float DIF,int value,float SANdam,char* image,char* des)
{
  this->tempDIF = DIF;
  this->DIF = DIF;
  this->value = value;
  this->SANDam= SANdam;
  this->avatar = newimage();
  getimage(this->avatar,image);
  this->des = des;
}

float Fantancy::getDif(){
  return this->DIF;
}

float Fantancy::getSANDam(){
  return this->SANDam;
}

int Fantancy::getValue(){
  return this->value;
}

void Fantancy::setImage(char* address){
	getimage(this->avatar, address);
}

PIMAGE Fantancy::getImage(){
	return this->avatar;
}

char* Fantancy::getDes(){
	return this->des;
}



//Ա����
class Member :public Creature
{
    protected:
      bool rest;
      float EMO;
      float DEX;
      float SAN;
      float buyed;
      int imageNumber;
      PIMAGE avatar = newimage();
    public:
      Member();
      void work(Fantancy f);
      void setRest(bool rest);
      void setImage(char* address);
      void setImageNumber(int);
      void setDEX(float num);
      void setEMO(float num);
      PIMAGE getImage();
      Member(float EMO,float DEX,float SAN,float buyed);
      float getEMO();
      bool getRest();
      float getSAN();
      float getDEX();
      float getBuyed();
      int getImageNumber();
      
};

Member::Member()
{
  this->EMO = 0.0;
  this->DEX = 0.0;
  this->SAN = 0.0;
  this->buyed = 0.0;
}

Member::Member(float EMO,float DEX,float SAN,float buyed)
{
  this->EMO = EMO;
  this->DEX = DEX;
  this->SAN = SAN;
  this->buyed = buyed;
  this->rest = false;
}

void Member::work(Fantancy f)
{
  float value = f.getValue();
  float hurt = f.getSANDam();
  float dif = f.getDif();
  if(0>dif && dif < 0.4){
  	float j = (this->getDEX() + rand() % 5 +1)/15;
  }
  if(0.4 >= dif && dif < 0.6){
  	float j = (this->getDEX() + rand() % 4 +1)/12;
  }
  if(0.6 >= dif && dif < 1){
  	float j = (this->getDEX() + rand() % 3 +1)/9;
  }
//���������
  float j = (rand() % 101) / 100.0;
  if(j >= dif){
    allProfit += value;
  }else{
  	if(this->EMO != 0){
  		if(hurt >= this->EMO){
  			this->EMO = 0;
		  }else{
		  	this->EMO -= hurt;
		  }
	  }else{
	  	if(hurt >= this->SAN){
  			this->SAN = 0;
		  }else{
		  	this->SAN -= hurt;
		  }
	  }

  }
}

float Member::getEMO(){
  return this->EMO;
}

float Member::getSAN(){
  return this->SAN;
}

float Member::getDEX(){
  return this->DEX;
}

float Member::getBuyed(){
  return this->buyed;
}

void Member::setImage(char* address){
	getimage(this->avatar, address);
}

PIMAGE Member::getImage(){
	return this->avatar;
}

int Member::getImageNumber(){
	return this->imageNumber;
}

void Member::setImageNumber(int num){
	this->imageNumber = num;
}

void Member::setDEX(float num){
	this->DEX = num;
}

void Member::setRest(bool rest){
	this->rest = rest;
}

void Member::setEMO(float num){
	this->EMO = num;
}

bool Member::getRest(){
	return this->rest;
}



//��̬���� 
static Member recruitList[3];//

static char* avatars[12] = {
"Ա������\\Ա��1.png",
"Ա������\\Ա��2.png",
"Ա������\\Ա��3.png",
"Ա������\\Ա��4.png"
,"Ա������\\Ա��5.png"
,"Ա������\\Ա��6.png"
,"Ա������\\Ա��7.png"
,"Ա������\\Ա��8.png"
,"Ա������\\Ա��9.png"
,"Ա������\\Ա��10.png"
,"Ա������\\Ա��11.png"
,"Ա������\\Ա��12.png"
};
static char* bavatars[12] = {
"Ա������\\Ա��b1.png",
"Ա������\\Ա��b2.png",
"Ա������\\Ա��b3.png",
"Ա������\\Ա��b4.png"
,"Ա������\\Ա��b5.png"
,"Ա������\\Ա��b6.png"
,"Ա������\\Ա��b7.png"
,"Ա������\\Ա��b8.png"
,"Ա������\\Ա��b9.png"
,"Ա������\\Ա��b10.png"
,"Ա������\\Ա��b11.png"
,"Ա������\\Ա��b12.png"
};

static Member memberList[12];//

static bool recruited[3] = {false,false,false};//

static int memberNumber = 0;//

static bool firstIn = true;//

static int allRestTime = 1;//

static MUSIC music;//

static int times = 0;

static float volume = 0.5f;

static int restTime = 1;//

static bool choosed[3] = {false,false,false};//

static bool choosedf[3] = {false,false,false};//

static int fantancyNumber = 0;//

static Fantancy fantancyList[6];//

static Fantancy all[14] = {
	*(new Fantancy(0.2,100,0.4,"����������\\��ŵ.png","��ŵ���ǵ�ŵ��")),
	*(new Fantancy(0.3,110,0.4,"����������\\ʧ����Ů.png","�㲱���Ϲ��ŵ���ʲô����")),
	*(new Fantancy(0.3,110,0.4,"����������\\���׵�����.png","лл��")),
	*(new Fantancy(0.4,120,0.5,"����������\\��ٷ���.png","�ó����ó����ö���!")),
	*(new Fantancy(0.2,100,0.2,"����������\\�������.png","ding~")),
	*(new Fantancy(0.3,110,0.3,"����������\\�ͽ���.png","���ǴӺܾ���ǰ�Ϳ�ʼ�������Ϊʲô�أ�")),
	*(new Fantancy(0.5,180,1.0,"����������\\5��7��.png","5��7�ա������Ѿ�û�м�����")),
	*(new Fantancy(0.5,180,1.2,"����������\\��.png","�ǺǺ�...����")),
	*(new Fantancy(0.6,240,2.0,"����������\\��������һ��.png","Ϊʲô��������ȥ����������")),
	*(new Fantancy(0.5,180,2.0,"����������\\���ϻ�Ѽ.png","��~")),
	*(new Fantancy(0.7,280,2,"����������\\����.png","������......")),
	*(new Fantancy(0.8,320,2.7,"����������\\������.png","�㣿�ң����Ǻ�......")),
	*(new Fantancy(0.8,300,2.5,"����������\\����.png","ֻ�Ǿ����Ĺ�������...")),
	*(new Fantancy(0.95,1000,3,"����������\\���밵.png","��ͼ...���ѡ����ǡ���")),
};



//������ 
int main()
{
	setcaption("������������");
	initgraph(1080, 720,0);	//��ʼ��ͼ�λ������������Ϊ1080x720�Ĵ���
	goTitle();
	return 0;
}



//�����б� 
void goJudge(){
	if(allProfit > 20000){
		gohe();
	}
	if(allProfit > 2500 && allProfit < 20000){
		gote();
	}
	if(allProfit < 2500){
		gobe();
	}
}

void gohe(){
	cleardevice();
	PIMAGE bg = newimage();
	getimage(bg, "he.jpg");
	putimage(0, 0, bg);
	getch();
	closegraph();
}

void gote(){
	cleardevice();
	PIMAGE bg = newimage();
	getimage(bg, "te.jpg");
	putimage(0, 0, bg);
	getch();
	closegraph();
}

void gobe(){
	cleardevice();
	PIMAGE bg = newimage();
	getimage(bg, "be.jpg");
	putimage(0, 0, bg);
	getch();
	closegraph();
}

void finishOneDay(){
	if(days == 7){
		goJudge();
		return;
	}
	days++;
	firstIn = true;
	choosedf[0] = false;
	choosedf[1] = false;
	choosedf[2] = false;
	recruited[0] = false;
	recruited[1] = false;
	recruited[2] = false;
	choosed[0] = false;
	choosed[1] = false;
	choosed[2] = false;
	restTime = allRestTime;
	for(int i = 0;i<12;i++){
		memberList[i].setRest(false);
	}
	goBegin();
}

void addF(int num){
	switch(days){
		case 1:
			fantancyList[fantancyNumber] = all[num];
			for(int i = num;i < 13;i++){
				all[i] = all[i+1]; 
			}
			fantancyNumber++;
			break;
		case 2:
			fantancyList[fantancyNumber] = all[num];
			for(int i = num;i < 12;i++){
				all[i] = all[i+1]; 
			}
			fantancyNumber++;
			break;
		case 3:
			fantancyList[fantancyNumber] = all[num + 2];
			for(int i = num + 2;i < 11;i++){
				all[i] = all[i+1]; 
			}
			fantancyNumber++;
			break;
		case 4:
			fantancyList[fantancyNumber] = all[num + 2];
			for(int i = num + 2;i < 10;i++){
				all[i] = all[i+1]; 
			}
			fantancyNumber++;
			break;
		case 5:
		    fantancyList[fantancyNumber] = all[num + 4];
			for(int i = num + 4;i < 9;i++){
				all[i] = all[i+1]; 
			}
			fantancyNumber++;
			break;
		case 6:
			fantancyList[fantancyNumber] = all[num + 5];
			for(int i = num + 5;i < 8;i++){
				all[i] = all[i+1]; 
			}
			fantancyNumber++;
			break;
	}
}

void goChoose(){
	setfont(20, 0, "����");
	int choosedCD = 0; 
	int choosed = 0;
	cleardevice();
	PIMAGE bg = newimage();
	getimage(bg, "����������.jpg"); 
	PIMAGE choices[3];
	char* dess[3];
	mouse_msg msg = {0};
	switch(days){
		case 1:
		case 2:
			choices[0] = all[0].getImage();
			dess[0] = all[0].getDes();
			choices[1] = all[1].getImage();
			dess[1] = all[1].getDes();
			choices[2] = all[2].getImage();	
			dess[2] = all[2].getDes();
			break;
		case 3:
		case 4:
			choices[0] = all[2].getImage();
			dess[0] = all[2].getDes();
			choices[1] = all[3].getImage();
			dess[1] = all[3].getDes();
			choices[2] = all[4].getImage();
			dess[2] = all[4].getDes();
			break;
		case 5:
		    choices[0] = all[4].getImage();
		    dess[0] = all[4].getDes();
			choices[1] = all[5].getImage();
			dess[1] = all[5].getDes();
			choices[2] = all[6].getImage();	
			dess[2] = all[6].getDes();
			break;
		case 6:
			choices[0] = all[6].getImage();
			dess[0] = all[6].getDes();
			choices[1] = all[7].getImage();
			dess[1] = all[7].getDes();
			choices[2] = all[8].getImage();
			dess[2] = all[8].getDes();
			break;
		case 7:
			goManage();
	}
	for ( ; is_run(); delay_fps(30))
	{
		if(choosedCD != 0){
			choosedCD = (choosedCD + 1) % 15;
		}
		while (mousemsg())
		{
			msg = getmouse();
		}
		if((int)msg.is_down() && msg.x > 27 && msg.x < 170 && msg.y > 26 && msg.y < 93){
		    goBegin();
		}
		if((int)msg.is_down() && msg.x > 826 && msg.x < 1080 && msg.y > 607 && msg.y < 720){
			addF(choosed);
		    goManage();
		}
		if((int)msg.is_down() && msg.x > 741 && msg.x < 802 && msg.y > 116 && msg.y < 264){
		    if(choosedCD == 0){
		    	choosedf[1] = false;
		    	choosedf[2] = false;
		    	choosedf[0] = true;
		    	choosed = 0;
			}else{
				choosedCD++; 
			}
		}
		if((int)msg.is_down() && msg.x > 741 && msg.x < 802 && msg.y > 277 && msg.y < 425){
		    if(choosedCD == 0){
		    	choosedf[1] = true;
		    	choosedf[2] = false;
		    	choosedf[0] = false;
		    	choosed = 1;
			}else{
				choosedCD++; 
			}
	    }
	    putimage(0, 0, bg);
		if((int)msg.is_down() && msg.x > 741 && msg.x < 802 && msg.y > 438 && msg.y < 586){
		    if(choosedCD == 0){
		    	choosedf[1] = false;
		    	choosedf[2] = true;
		    	choosedf[0] = false;
		    	choosed = 2;
			}else{
				choosedCD++; 
			}
		}
		putimage(180,116,choices[0]);
		xyprintf(405,121,dess[0]);
		if(choosedf[0]){
			xyprintf(405,141,"��ѡ��");
		}
		putimage(180,277,choices[1]);
		xyprintf(405,282,dess[1]);
		if(choosedf[1]){
			xyprintf(405,302,"��ѡ��");
		}
		putimage(180,438,choices[2]);
		xyprintf(405,443,dess[2]);
		if(choosedf[2]){
			xyprintf(405,463,"��ѡ��");
		}
	}
}

void goSetting(){
	cleardevice();
	PIMAGE bg = newimage();
	getimage(bg, "����.jpg"); 
	putimage(0, 0, bg);
	setfont(16, 0, "����");
	xyprintf(20, 100, "P������������M����С����");
	xyprintf(20, 115, "��ʼ��������Ϊ50% ÿ�α仯10%!");
	xyprintf(20, 130, "��R���  ��Y���  ��G����");
	mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(30))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		if((int)msg.is_down() && msg.x > 49 && msg.x < 225 && msg.y > 47 && msg.y < 110){
		    goBegin();
		}
			while (kbmsg()) {
				key_msg keyMsg = getkey();
				if (keyMsg.msg != key_msg_down)
					continue;

				DWORD status = music.GetPlayStatus();
				int key = keyMsg.key;
				switch (key) {
					
					//������ɫ ÿ�α䶯10% 
				case 'P':		//��������
					if ((volume += 0.1f) >= 1)
						volume = 1;
					music.SetVolume(volume);
					break;
				case 'M':		//��С����
					if ((volume -= 0.1f) < 0)
						volume = 0;
					music.SetVolume(volume);
					break;
					
					//������ɫ 				
				case 'R':		//change Red
					//choose_color=1;
					setcolor(EGERGB(0xA8, 0, 0));
					xyprintf(20, 100, "P������������M����С����");
	xyprintf(20, 115, "��ʼ��������Ϊ50% ÿ�α仯10%!");
	xyprintf(20, 130, "��R���  ��Y���  ��G����");
					break;
				case 'Y':		//change Yellow
					//choose_color=2;
					setcolor(EGERGB(0xFC, 0xFC, 0x54));
					xyprintf(20, 100, "P������������M����С����");
	xyprintf(20, 115, "��ʼ��������Ϊ50% ÿ�α仯10%!");
	xyprintf(20, 130, "��R���  ��Y���  ��G����");
					break;
				case 'G':		//change Green
					//choose_color=3;	
					setcolor(EGERGB(0x0, 0xFF, 0x0));	
					xyprintf(20, 100, "P������������M����С����");
	xyprintf(20, 115, "��ʼ��������Ϊ50% ÿ�α仯10%!");
	xyprintf(20, 130, "��R���  ��Y���  ��G����");					
					break;
				}
			}
	}
	
}

void rest(int num){
	if(memberList[num].getRest()){
		return;
	}
	if(restTime == 0){
		return;
	}
	memberList[num].setRest(true);
	memberList[num].setEMO(10);
	restTime--;
}

void train(int num){
	if(allProfit <= (memberList[num].getDEX() * 50 + 150)){
		return;
	}
	allProfit -= (memberList[num].getDEX() * 50 + 150);
	memberList[num].setDEX(memberList[num].getDEX() + 1);
}

void goTitle(){
	cleardevice();
	PIMAGE init = newimage();
	getimage(init, "��ʼui.png"); 
	putimage(0, 0, init);
	mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(30))
	{
		//��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
		//���Ƶأ��к�kbhit��������ĺ���MouseHit�����ڼ����û�������Ϣ
		while (mousemsg())
		{
			msg = getmouse();
		}

		if((int)msg.is_down() && msg.x > 778 && msg.x < 1016 && msg.y > 336 && msg.y < 438){
		    goBegin();
		}
		if((int)msg.is_down() && msg.x > 778 && msg.x < 1016 && msg.y > 467 && msg.y < 569){
		    closegraph();
		}
	}
}

void goBegin(){
	cleardevice();
	bool run = true;
	int n = 0;
	int k = 0;
	int speed = 1;
	bool up = false;
	setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	setfont(40, 0, "����");
	
	if(times++ == 0)
	{
	setcolor(EGERGB(0x0, 0xFF, 0x0));
	 } 
	
	music.OpenFile("Copilot Strategic Sound��Music - The Drunken Whaler.mp3");
	music.Play(0);
		music.SetVolume(volume);

	cleardevice();
	PIMAGE keys_manage = newimage();
	PIMAGE keys_exit = newimage();
	PIMAGE keys_open = newimage();
	PIMAGE keys_setting = newimage();
	PIMAGE operation = newimage();
	getimage(operation, "����.jpg");
	getimage(keys_manage, "keys_manage.png");
	getimage(keys_exit, "keys_exit.png");
	getimage(keys_open, "keys_open.png");
	getimage(keys_setting, "keys_setting.png");
	mouse_msg msg = {0};

	//֡�� 
	for( ;is_run() && run; delay_fps(30)){
		while (mousemsg())
		{
			msg = getmouse();
		}
		if(k == 30){
			speed = -1;
		}
		if(k == -30){
			speed = 1;
		}
		k = k + speed;
		n = k/4;
		if((int)msg.is_down() && msg.x > 800 && msg.x < 1028 && msg.y > (480+n)&& msg.y < (581+n)){
			run = false;
			music.Pause();
			goTitle();
		}
		if((int)msg.is_down() && msg.x > 800 && msg.x < 1028 && msg.y > (330+n)&& msg.y < (431+n)){
			run = false;
			music.Pause();
			if(firstIn){
				changeRecruitList();
				firstIn = false;
		    }
			goControl();
		}
		if((int)msg.is_down() && msg.x > 500 && msg.x < 728 && msg.y > (400+n)&& msg.y < (501+n)){	
			run = false;
			music.Pause();
			goChoose();
		}
		if((int)msg.is_down() && msg.x > 500 && msg.x < 728 && msg.y > (550+n)&& msg.y < (651+n)){
			run = false;
			music.Pause();
			goSetting();
		}
		putimage(0, 0, operation);
		xyprintf(0,0,"��%d��",days);
		xyprintf(0,40,"�ʽ�%.2lf",allProfit);
		putimage_alphablend(NULL,keys_open,500, 400+n, 0x80);
		putimage_alphablend(NULL,keys_exit,800, 480+n, 0x80);
		putimage_alphablend(NULL,keys_manage,800, 330+n, 0x80);
		putimage_alphablend(NULL,keys_setting,500, 550+n, 0x80);
		
	}
	
	
}

void manageShow(int choosed,int xe,int ye){
	Member tempMemberList[4];
	if(fantancyList[choosed-1].getImage() == NULL){
		return;
	}
	for(int i = 0;i<4;i++){
		tempMemberList[i] = memberList[3 * i + (choosed - 1)%3];
		if(tempMemberList[i].getImage() != NULL){
			putimage(703,158 + i * 135,tempMemberList[i].getImage());
			xyprintf(890,180 + i * 135,"%.2f",tempMemberList[i].getDEX());
			xyprintf(890,210 + i * 135,"%.2f",tempMemberList[i].getSAN());
			xyprintf(890,240 + i * 135,"%.2f",tempMemberList[i].getEMO());
		}
	}
	putimage(665,0,fantancyList[choosed-1].getImage());
}

void showProfit(){
	xyprintf(0,0,"%.2f",allProfit);
}

void goManage(){
	music.OpenFile("������ - Vanquish.mp3");
	music.Play(0);
	music.SetVolume(volume);
	int oneSecond = 0;
	int oneSecond1 = 0;
	srand((unsigned)time(NULL));
	int workCD = 0;
	int choosed = 1;
	int choosedm = 0;
	int xe = 0;
	int ye = 0;
	cleardevice();
	mouse_msg msg = {0};
	
	//������Ⱦ 
	PIMAGE bg = newimage();
	getimage(bg, "work.png");
	putimage(0, 0, bg);
	 
	//��������Ⱦ 
	PIMAGE opera = newimage();
	getimage(opera, "Ա��������.png");
	putimage_alphablend(NULL,opera,665,0, 0xD0);
	
	//������Ⱦ 
	PIMAGE faculty[3] = {newimage(),newimage(),newimage()};
    getimage(faculty[0], "����1.png");
    getimage(faculty[1], "����2.png");
    getimage(faculty[2], "����3.png");
	putimage(311 - 172,176,faculty[0]);
	putimage(311 - 172,331,faculty[1]);
	putimage(311 - 172,486,faculty[2]);
	
	//����������Ⱦ 
	PIMAGE core = newimage();
	getimage(core,"ͷ.png");
	putimage(370 - 172,0,core);
	
	//������Ⱦ 
	PIMAGE finish = newimage();
	getimage(finish,"����.png");
	putimage(0,655,finish);
	
	//�߿���Ⱦ 
	PIMAGE nothing = newimage();
	getimage(nothing,"�߿�.png");
	for(int i = 0;i < 6;i++){
		xe = i / 3;
		ye = i % 3;
		if(fantancyList[i].getImage() != NULL){
			putimage(466 + xe * 155 - 172,176 + ye * 155,fantancyList[i].getImage());
		}else{
			putimage(466 + xe * 155 - 172,176 + ye * 155,nothing);
		}
	}
	manageShow(choosed,xe,ye);
	showProfit();
	//֡�� 
	for( ;is_run(); delay_fps(30)){
		if(workCD != 0){
			workCD = (workCD + 1) % 30;
		}
		while (mousemsg())
		{
			msg = getmouse();
		}
		if((int)msg.is_down() && msg.x > 466 - 172 && msg.x < 466 + 148 - 172 && msg.y > 176 && msg.y < 176 + 148){
			choosed = 1;
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 466 - 172 && msg.x < 466 + 148 - 172 && msg.y > 331 && msg.y < 331 + 148){
			choosed = 2;
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 466 - 172 && msg.x < 466 + 148 - 172 && msg.y > 486 && msg.y < 486 + 148){
			choosed = 3;
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 621 - 172 && msg.x < 621 + 148 - 172 && msg.y > 176 && msg.y < 176 + 148){
			choosed = 4;
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 621 - 172 && msg.x < 621 + 148 - 172 && msg.y > 331 && msg.y < 331 + 148){
			choosed = 5;
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 621 - 172 && msg.x < 621 + 148 - 172 && msg.y > 486 && msg.y < 486 + 148){
			choosed = 6;
			manageShow(choosed,xe,ye);
		}
		
		
		//�������ĸ���λ 
		if((int)msg.is_down() && msg.x > 947 && msg.x < 1003 && msg.y > 158 && msg.y < 158 + 137){
			if(workCD == 0){
				if(!memberList[3 * 0 + (choosed-1) % 3].getRest()){
				    if(memberList[3 * 0 + (choosed-1) % 3].getSAN() == 0){
						oneSecond++;
					}else{
						memberList[3 * 0 + (choosed-1) % 3].work(fantancyList[choosed-1]);
					}	
				}else{
					oneSecond1++;
				}
				workCD++; 
			}
			showProfit();
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x >947 && msg.x < 1003 && msg.y > 158+137 && msg.y < 158 + 137 * 2){
			if(workCD == 0){
				if(!memberList[3 * 1 + (choosed-1) % 3].getRest()){
				    if(memberList[3 * 1 + (choosed-1) % 3].getSAN() == 0){
						oneSecond++;
					}else{
						memberList[3 * 1 + (choosed-1) % 3].work(fantancyList[choosed-1]);
					}	
				}else{
					oneSecond1++;
				}
				workCD++; 
			}
			showProfit();
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 947 && msg.x < 1003 && msg.y > 158+137 * 2 && msg.y < 158 + 137 * 3){
			if(workCD == 0){
				if(!memberList[3 * 2 + (choosed-1) % 3].getRest()){
				    if(memberList[3 * 2 + (choosed-1) % 3].getSAN() == 0){
						oneSecond++;
					}else{
						memberList[3 * 2 + (choosed-1) % 3].work(fantancyList[choosed-1]);
					}	
				}else{
					oneSecond1++;
				}
				workCD++; 
			}
			showProfit();
			manageShow(choosed,xe,ye);
		}
		if((int)msg.is_down() && msg.x > 947 && msg.x < 1003 && msg.y > 158+137 * 3 && msg.y < 158 + 137 * 4){
			if(workCD == 0){
				if(!memberList[3 * 3 + (choosed-1) % 3].getRest()){
				    if(memberList[3 * 3 + (choosed-1) % 3].getSAN() == 0){
						oneSecond++;
					}else{
						memberList[3 * 3 + (choosed-1) % 3].work(fantancyList[choosed-1]);
					}	
				}else{
					oneSecond1++;
				}
				workCD++; 
			}
			showProfit();
			manageShow(choosed,xe,ye);
		}
		if(oneSecond){
			warning("��Ա���Ѿ��޷�������");
			oneSecond = (oneSecond + 1) % 30;
		}
		if(oneSecond1){
			warning("��Ա��������Ϣ���޷�����");
			oneSecond1 = (oneSecond1 + 1) % 30;
		}
		if((int)msg.is_down() && msg.x > 0 && msg.x < 175 && msg.y > 655 && msg.y < 720){
			music.Pause();
			finishOneDay();
		}
	}
	
	    
}

void goRules(){
	cleardevice();
	PIMAGE bg = newimage();
	getimage(bg, "׼��.jpg");
	mouse_msg msg = {0};
	
	//֡�� 
	for( ;is_run(); delay_fps(30)){
		while (mousemsg())
		{
			msg = getmouse();
		}
		if((int)msg.is_down() && msg.x > 948 && msg.x < 1080 && msg.y > 646 && msg.y < 720){
			goControl();
		}
		putimage(0, 0, bg);
	}
}

void changeRecruitList(){
	int DEX;
	int buyed;
	//֡�� 
	for(int i = 0;i< 3;i++){
		DEX = rand()%3 + 1;
		switch(DEX){
		case 1:
			buyed = 500;
			break;
		case 2:
			buyed = 700;
			break;
        case 3:
        	buyed = 950;
        	break;
	}
	recruitList[i] =*(new Member(10,DEX,10,buyed));
	int n = rand() % 12;
	recruitList[i].setImage(bavatars[n]);
	recruitList[i].setImageNumber(n);
	}
}

void recruit(){
	int oneSecond = 0;
	for(int i = 0;i < 3;i++){
		if(allProfit <= recruitList[i].getBuyed()){
			return;
		}
		if(choosed[i] && !recruited[i]){
			memberList[memberNumber] = recruitList[i];
			memberList[memberNumber].setImage(avatars[recruitList[i].getImageNumber()]);
			choosed[i] = false;
			recruited[i] = true; 
			memberNumber++;
			allProfit -= recruitList[i].getBuyed();
		}
	}
}

void showMember(int num){
	Member theOne = memberList[num];
	PIMAGE avatar = theOne.getImage();
	putimage(0,320,avatar);
	xyprintf(95,645,"%.0f",150 + theOne.getDEX() * 50);
	xyprintf(300,360,"%.2f",theOne.getDEX());
	xyprintf(300,400,"%.2f",theOne.getSAN());
	
	xyprintf(300,440,"%.2f",theOne.getEMO());
}

void restExtend(){
	if(allProfit < 1000){
		return;
	}
	allProfit -= 1000;
	restTime += 1;
	allRestTime += 1;
}

void printAvatar(){
	int xe,ye;
	for(int i = 0;i < 12; i++){
		xe = i % 3;
		ye = i / 3;
		if(memberList[i].getImageNumber() != NULL){
			putimage(729 + 117 * xe,142 + 117 * ye,memberList[i].getImage());
		}
	}
}

void warning(char* str){
	xyprintf(0,400,str);
}

void goControl(){
	int xe;
	int ye;
	int restUpCD = 0;
	int choose1CD = 0;
	int choose2CD = 0;
	int choose3CD = 0;
	int oneSecond = 0;
	int trainCD = 0;
	bool show = false;
	bool choosed1 = false;
	bool choosed2 = false;
	bool choosed3 = false;
	bool book = false;
	srand((unsigned)time(NULL));//���������
	cleardevice();
	PIMAGE bg = newimage();
	setfont(20, 0, "����");
	getimage(bg, "����.jpg");
	mouse_msg msg = {0};
	
	//֡�� 
	for( ;is_run(); delay_fps(30)){
		if((int)msg.is_down() && msg.x > 144 && msg.x < 339 && msg.y > 0 && msg.y < 195){
			if(choose1CD == 0){
				choosed[0] = !choosed[0];
				choose1CD++; 
			}
		}
		if((int)msg.is_down() && msg.x > 339 && msg.x < 534 && msg.y > 0 && msg.y < 195){
			if(choose2CD == 0){
				choosed[1] = !choosed[1];
				choose2CD++; 
			}
		}
		if((int)msg.is_down() && msg.x > 534 && msg.x < 729 && msg.y > 0 && msg.y < 195){
			if(choose3CD == 0){
				choosed[2] = !choosed[2];
				choose3CD++; 
			}
		}
		if((int)msg.is_down() && msg.x > 729 && msg.x < 1080 && msg.y > 611 && msg.y < 720){
			goBegin();
		}
		if((int)msg.is_down() && msg.x > 986 && msg.x < 1080 && msg.y > 0 && msg.y < 142){
			goRules();
		}
		if((int)msg.is_down() && msg.x > 414 && msg.x < 574 && msg.y > 476 && msg.y < 720){
			if(restUpCD == 0 && restTime < 5){
				restExtend();
				restUpCD++;
			}
			if(restUpCD == 0 && restTime >=5 && oneSecond != 30){
				oneSecond++;
			}
		}
		if((int)msg.is_down() && msg.x > 0 && msg.x < 144 && msg.y > 0 && msg.y < 195){
			recruit();
		}
		if(restUpCD){
			restUpCD = (restUpCD + 1) % 15;
		}
		if(choose1CD){
			choose1CD = (choose1CD + 1) % 15;
		}
		if(choose2CD){
			choose2CD = (choose2CD + 1) % 15;
		}
		if(choose3CD){
			choose3CD = (choose3CD + 1) % 15;
		}
		if(trainCD){
			trainCD = (trainCD + 1) % 15;
		}
		if((int)msg.is_down() && msg.x > 729 && msg.x < 1080 && msg.y > 142 && msg.y < 611){
			xe = (msg.x - 729) / 117;
			ye = (msg.y - 142) / 117;
			show = true;
		}
		if((int)msg.is_down() && msg.x > 180 && msg.x < 413 && msg.y > 543 && msg.y < 720 && show && restTime != 0){
			rest(xe + 3 * ye);
		}
		if((int)msg.is_down() && msg.x > 0 && msg.x < 180 && msg.y > 500 && msg.y < 720 && show){
			if(trainCD == 0){
			    train(xe + 3 * ye);
				trainCD++;
			}

		}
		if((int)msg.is_down() && msg.x > 180 && msg.x < 413 && msg.y > 543 && msg.y < 720 && show){
			rest(xe + 3 * ye);
		}
		while (mousemsg())
		{
			msg = getmouse();
		}
		
		//չʾ�� 
		putimage(0, 0, bg);
		if(!recruited[0]){
			putimage(144,0,recruitList[0].getImage());
			xyprintf(154,210,"DEX: %.2f",recruitList[0].getDEX());
			xyprintf(154,230,"SAN: %.2f",recruitList[0].getSAN());
			xyprintf(154,250,"EMO: %.2f",recruitList[0].getEMO());
			xyprintf(154,270,"�����ʽ�: %.2f",recruitList[0].getBuyed());
			if(choosed[0]){
				xyprintf(154,290,"��ѡ��");
			}
		}else{
			xyprintf(154,210,"����Ƹ");
		}
		if(!recruited[1]){
			putimage(339,0,recruitList[1].getImage());
			xyprintf(349,210,"DEX: %.2f",recruitList[1].getDEX());
			xyprintf(349,230,"SAN: %.2f",recruitList[1].getSAN());
			xyprintf(349,250,"EMO: %.2f",recruitList[1].getEMO());
			xyprintf(349,270,"�����ʽ�: %.2f",recruitList[1].getBuyed());
			if(choosed[1]){
				xyprintf(349,290,"��ѡ��");
			} 
		}else{
			xyprintf(349,210,"����Ƹ");
		}
		if(!recruited[2]){
			putimage(534,0,recruitList[2].getImage());
			xyprintf(544,210,"DEX: %.2f",recruitList[2].getDEX());
			xyprintf(544,230,"SAN: %.2f",recruitList[2].getSAN());
			xyprintf(544,250,"EMO: %.2f",recruitList[2].getEMO());
			xyprintf(544,270,"�����ʽ�: %.2f",recruitList[2].getBuyed());
			if(choosed[2]){
				xyprintf(544,290,"��ѡ��");
			} 
		}else{
			xyprintf(544,210,"����Ƹ");
		}
		if(oneSecond){
			warning("���ݴ����Ѵ����ޣ�");
			oneSecond = (oneSecond + 1) % 30;
		}
		if(show){
			showMember(xe + ye * 3);
		}
		xyprintf(10,263,"%.2lf",allProfit);
		xyprintf(450,410,"%d",restTime);
		printAvatar();
	}
}
