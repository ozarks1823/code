// khai bao thu vien
#include<iostream> // khai bao nhap xuat
#include<string.h> // khai bao su dung chuoi ky tu
//#include<fstream> //khai bao su dung file voi c++
using namespace std;
struct Employee{
	string hoTen, gioiTinh, queQuan, Chucvu;
	int namSinh, maNV;
	float luong;
};
struct node{
	Employee data;
	node *next;
};
void init(node *&head){ //khoi tao 1 dslk
	head=NULL;
}
node* createNode(Employee x){ //tao node
	node *p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}
node *addFirst(node *&head, Employee x){
	node *p= createNode(x);
	if(head==NULL)
		head=p;
	else{
	p->next=head;
	head=p;
	}
}
bool sosanh(string s1, string s2){
	if(s1==s2)
		return true;
	else
		return false;
}
void NhapNV(Employee a, int n, node *&head){
		node *p=head;
		int dem=0, dem1;
	    for(int i = 0; i < n; i++){
	        cout<<"\n	*	Nhan vien thu  "<<i+1<<"	*"<<endl;
	        cout<<"\n	Nhap ma so nhan vien:				";
	        cin>>a.maNV;
	        if (a.maNV<0){
	        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
	   		}
	        else{
	        	if(a.maNV>0){
		    		dem1=0;
				for(node*p=head;p!=NULL;p=p->next){
					if(p->data.maNV==a.maNV){
		        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
		        	dem1=1;
		    		}
		    	}
		    	if(dem1!=1){
			        fflush(stdin);
			        cout<<"\n	Nhap ho va ten (nhap ten truoc, ho sau):	";
			        getline(cin,a.hoTen);
					cout<<"\n	Nhap gioi tinh (nam / nu):			";
			        getline(cin,a.gioiTinh);
					while(a.gioiTinh=="Nam" || a.gioiTinh=="Nu"){
						cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
						cout<<"\n	Nhap gioi tinh:		";
						fflush(stdin);
			       		getline(cin,a.gioiTinh);
					}
					cout<<"\n	Nhap nam sinh:					";
			        cin>>a.namSinh;// nhap getline dung cho chuoi ki tu co cach trong, khai bao ham string, neu nhap so dung cin
			        if(a.namSinh<=0)
			        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
			        else{
				        fflush(stdin); //cin.ignore(): xoa bo nho dem
				        cout<<"\n	Nhap que quan:					";
				        getline(cin,a.queQuan);
				    	cout<<"\n	Nhap chuc vu:					";
				        getline(cin,a.Chucvu);
				        cout<<"\n	Nhap luong (trieu dong):			";
				        cin>>a.luong;
				        if(a.namSinh<=0)
				        	cout<<"\n\t VUI LONG NHAP LAI!!!"<<endl;
				        else{
					        fflush(stdin);
							dem=dem+1;
					        cout<<"\n	DA NHAP THANH CONG "<<dem<<" NHAN VIEN"<<endl;
					  		cout<<"--------------------------------------------------------------------------------------"<<endl;
					  		addFirst(head, a);
					  		}
						}
	 				}
	  			}
			}
		}
}
/*void readEmployees(node *&head){
	ifstream f; // khai bao 1 bien de doc du lieu tu 1 file (co the thay bang fstream)
	f.open("Employees.txt", ios::in); // mo file, ios::in d�ng de Mo cho c�c hoat dong dau v�o. (mode mac dinh cua ifstream)
	while(!f.eof()){ //khi chua toi cuoi file thi tiep tuc doc
		Employee e; 
		f>>e.maNV;
		f.ignore(); //can co de bo qua gia tri dem
		getline(f, e.hoTen); // dung string thi su dung getline (co the lay ki tu sau dau cach)
		getline(f, e.gioiTinh);
		f>>e.namSinh;
		f.ignore();
		getline(f, e.queQuan);
		getline(f, e.Chucvu);
		f>>e.luong;
		f.ignore();
		addFirst(head, e);
	}
	f.close();
} //ket thuc qua trinh se cho ra 1 dslk chua thong tin cac nhan vien
*/

void printfEmployee(Employee e){
	cout<<"	Ma So Nhan Vien:		"<<e.maNV<<endl;
	cout<<"	Ho Ten:				"<<e.hoTen<<endl;
	cout<<"	Gioi Tinh:			"<<e.gioiTinh<<endl;
	cout<<"	Nam Sinh:			"<<e.namSinh<<endl;
	cout<<"	Que Quan:			"<<e.queQuan<<endl;
	cout<<"	Chuc Vu:			"<<e.Chucvu<<endl;
	cout<<"	Luong nhan duoc:		"<<e.luong<<" trieu dong"<<endl;
	cout<<"==========================================================="<<endl;
}
void printf(node*head){
	node *p = head;
	while(p != NULL){
		printfEmployee(p->data);
		p = p->next;
	}
}
node *searchLuong(node *head, float luongDau, float luongCuoi){
	node *kq;
	init(kq);
	node *p=head;
	while(p!=NULL){
		if(p->data.luong>=luongDau && p->data.luong<=luongCuoi)
			addFirst(kq,p->data);
			p=p->next;
	}
	return kq;
}
node *searchMaNV(node *head, int manv){
	node *kq;
	init(kq);
	node *p=head;
	while(p!=NULL){
		if(p->data.maNV==manv)
			addFirst(kq,p->data);
			p=p->next;
	}
	return kq;
}

node *searchTen(node *head, string ten){
	node *kq;
	init(kq);
	node *p=head;
	string tolower(p->data.hoTen);
	while(p!=NULL){
		if(p->data.hoTen.find(ten) != string::npos) // find tim kiem chuoi con trong 1 chuoi lon,	va tra ve gia tri khac npos
			addFirst(kq,p->data);
			p=p->next;
	}
	return kq;
}
void deleteFirst(node *&head){
	if(head!=NULL){
		node *p=head;
		head=p->next;
		p->next=NULL;
		delete(head);
	}
}
void deleteLast(node *&head){
	if(head != NULL){
		//xac dinh node cuoi va node truoc cua node cuoi
		node *last = head;
		node *prev = NULL;
		while(last->next != NULL){
			prev = last;
			last=last->next;
		}
		if(prev == NULL)
			deleteFirst(head);
		prev->next = NULL;
		delete(last);
	}
}
void deleteNode(node *&head, Employee a,int manv){
	if(head != NULL){
		node *p = head;
		node *q = searchMaNV(head, manv);
		node *prev=NULL;
		cout<<"\n\t THONG TIN NHAN VIEN CO MA SO "<<manv<<" MA BAN MUON XOA"<<endl;
		printf(q);
		while(p != NULL && p->data.maNV != q->data.maNV){
				prev=p;
				p=p->next;
		}
		if(p!=NULL){	
			if(prev==NULL)
				deleteFirst(head);
			prev->next = p->next;
			p->next=NULL;
			delete(p);
		}
	}
}
void clean(node *&head){
	while(head!=NULL){ //neu head=null no se cho ra danh sach trong
		deleteFirst(head);
	}
}
void sortHoTenAZ(node *&head){
	for(node *p=head; p!=NULL; p=p->next){
		for(node *q=p->next; q!=NULL; q=q->next){
			if(p->data.hoTen > q->data.hoTen)
				swap(p->data , q->data);
			else if(p->data.hoTen == q->data.hoTen){
				if(p->data.maNV > q->data.maNV)
					swap(p->data, q->data);
			}
		}
	}
}
void sortHoTenZA(node *&head){
	for(node *p=head; p!=NULL; p=p->next){
		for(node *q=p->next; q!=NULL; q=q->next){
			if(p->data.hoTen < q->data.hoTen)
				swap(p->data , q->data);
			else if(p->data.hoTen == q->data.hoTen){
				if(p->data.maNV > q->data.maNV)
					swap(p->data, q->data);
			}
		}
	}
}
void sortLuongGiam(node *&head){
	for(node *p=head; p!=NULL; p=p->next){
		for(node *q=p->next; q!=NULL; q=q->next){
			if(p->data.luong < q->data.luong)
				swap(p->data , q->data);
			else if(p->data.luong == q->data.luong){
				if(p->data.maNV > q->data.maNV)
					swap(p->data, q->data);
			}
		}
	}
}
void sortLuongTang(node *&head){
	for(node *p=head; p!=NULL; p=p->next){
		for(node *q=p->next; q!=NULL; q=q->next){
			if(p->data.luong > q->data.luong)
				swap(p->data , q->data);
			else if(p->data.luong == q->data.luong){
				if(p->data.maNV > q->data.maNV)
					swap(p->data, q->data);
			}
		}
	}
}
void menu(){
	cout<<"\t\t\t	QUAN LY NHAN VIEN "<<endl; // \t = tab;
	cout<<"\t	********************************************"<<endl;
	cout<<"\t1.	Them n nhan vien"<<endl;
	cout<<"\t2.	Xuat thong tin nhan vien"<<endl;
	cout<<"\t3.	Tim nhan vien theo yeu cau"<<endl;
	cout<<"\t4.	Sap xep nhan vien theo yeu cau"<<endl;
	cout<<"\t5.	Xoa 1 nhan vien theo yeu cau"<<endl;
	cout<<"\t6.	Close"<<endl;
}
void menu1(){
	cout<<"\t1.	Tim nhan vien theo ten nhan vien"<<endl;
	cout<<"\t2.	Tim nhan vien theo ma so nhan vien"<<endl;
	cout<<"\t3.	Tim nhan vien co luong trong 1 khoang"<<endl;
}
void menu2(){
	cout<<"\t1.	Sap xep nhan vien theo ten A->Z"<<endl;
	cout<<"\t2.	Sap xep nhan vien theo ten Z->A"<<endl;
	cout<<"\t3.	Sap xep nhan vien theo luong tang dan"<<endl;
	cout<<"\t4.	Sap xep nhan vien theo luong giam dan"<<endl;
}
void menu3(){
	cout<<"\t1. Xoa 1 nhan vien o vi tri dau danh sach"<<endl;
	cout<<"\t2. Xoa 1 nhan vien o vi tri cuoi danh sach"<<endl;
	cout<<"\t3. Xoa 1 nhan vien theo Ma So Nhan Vien"<<endl;
}
int main(){
	node *head;
	init(head);
//	readEmployees(head);
	Employee a;
	int option;
	while(1){
		do{
			cout<<"\n\n";
			menu();
			cout<<"\n	VUI LONG CHON 1 NOI DUNG DE LAM (chon bang cach nhan so tuong ung):	";
			cin>>option;
		}while(option <= 0);		
		switch(option){
			case 1:{
				system("cls");
				int n;
				cout<<"\n\t\t	THEM N NHAN VIEN\n"<<endl;
				cout<<"\n	Moi nhap so nhan vien muon them vao:		";
				cin>>n;
				createNode(a);
				NhapNV(a, n, head);
				break;
			}
			case 2:{
				system("cls");
				cout<<"\n\t\t	XUAT THONG TIN NHAN VIEN\n"<<endl;
				cout<<"\n________________________DANH SACH NHAN VIEN________________________"<<endl;
				printf(head);
				if(head==NULL)
					cout<<"\n		  	  DANH SACH RONG"<<endl;
				break;
			}
			case 3:{
				system("cls");
				int option1;
				cout<<"\n\n";
				cout<<"\n\t\t	TIM NHAN VIEN THEO YEU CAU\n"<<endl;
				menu1();
				cout<<"\n	HAY CHON MOT YEU CAU (Chon theo so dau moi dong):	";
				cin>>option1;
				if (head == NULL)
					cout<<"\n	*	DANH SACH DANG RONG NEN KHONG TIM DUOC	*"<<endl;
				else{
					switch(option1){
						case 1:{
							string timTen;
							cin.ignore();
							cout<<"\n	Moi nhap Ten (mot ten de chuong trinh chay) nhan vien ma ban muon tra thong tin:	"<<endl;
							cout<<"	";
							cin>>timTen;
							node *kqTen=searchTen(head,timTen);
							printf(kqTen);
							if (kqTen == NULL)
								cout<<"\n	Khong co nhan vien co Ten nhu tren"<<endl;
							break;
						}
						case 2:{
							int timMaNV;
							cin.ignore(); //=fflush(stdin)
								cout<<"\n	Moi nhap Ma so nhan vien ma ban muon tra thong tin (gom 5 so):	"<<endl;
								cout<<"	";
								cin>>timMaNV;
								node *kqMaNV=searchMaNV(head,timMaNV);
								printf(kqMaNV);
								if (kqMaNV == NULL)
									cout<<"\n	Khong co nhan vien co Ma so nhu tren"<<endl;
							break;
						}
						case 3:{
							float luongDau, luongCuoi;
							cin.ignore();
							if (head == NULL)
								cout<<"\n	DANH SACH DANG RONG NEN KHONG TIM DUOC"<<endl;
							else{
								cout<<"\n	Moi nhap gioi han dau cua luong (trieu dong) muon tra:	";
								cin>>luongDau;
								cout<<"\n	Moi nhap gioi han cuoi cua luong (trieu dong) muon tra:	";
								cin>>luongCuoi;
								cin.ignore();
								node *kqLuong=searchLuong(head, luongDau, luongCuoi);
								cout<<"	------------DANH SACH NHAN VIEN CO KHOANG GIA TRI LUONG TU "<<luongDau<<" (TRIEU DONG) DEN "<<luongCuoi<<" (TRIEU DONG)------------"<<endl;
								printf(kqLuong);
								if (kqLuong == NULL)
									cout<<"\n	Khong co nhan vien co khoang gia tri Luong nhu tren"<<endl;
								}
							break;
						}
					}
				}
				break;				
			}
			case 4:{
				system("cls");
				int option2;
				cout<<"\n\n";
				cout<<"\n\t\t	SAP XEP NHAN VIEN THEO YEU CAU\n"<<endl;
				menu2();
				cout<<"\n	HAY CHON MOT YEU CAU (Chon theo so dau moi dong):	";
				cin>>option2;
				if (head == NULL)
					cout<<"\n	DANH SACH DANG RONG NEN KHONG TIM DUOC"<<endl;
				else{
					switch(option2){
						case 1:{
								sortHoTenAZ(head);
								cout<<"\n\t\t DANH SACH SAU KHI SAP XEP THEO HO TEN A->Z"<<endl;
								printf(head);		
							break;
						}
						case 2:{
								sortHoTenZA(head);
								cout<<"\n\t\t DANH SACH SAU KHI SAP XEP THEO HO TEN Z->A"<<endl;
								printf(head);		
							break;
						}
						case 3:{
								sortLuongTang(head);
								cout<<"\n\t\t DANH SACH SAU KHI SAP XEP THEO LUONG TANG DAN"<<endl;
								printf(head);
							break;
						}
						case 4:{
								sortLuongGiam(head);
								cout<<"\n\t\t DANH SACH SAU KHI SAP XEP THEO LUONG GIAM DAN"<<endl;
								printf(head);
							break;
						}
					}
				}
				break;
			}
			case 5:{
				system("cls");
				int option3;
				cout<<"\n\n";
				cout<<"\n\t\t	XOA 1 NHAN VIEN THEO YEU CAU\n"<<endl;
				menu3();
				cout<<"\n	HAY CHON MOT YEU CAU (Chon theo so dau moi dong):	";
				cin>>option3;
				if (head == NULL)
					cout<<"\n	DANH SACH DANG RONG NEN KHONG TIM DUOC"<<endl;
				else{
					switch(option3){
						case 1:{
							cout<<"\n	----------DANH SACH TRUOC KHI XOA DAU-------------\n"<<endl;
							printf(head);
							deleteFirst(head);
							cout<<"\n	----------DANH SACH SAU KHI XOA DAU-------------"<<endl;
							printf(head);
							if(head==NULL)
								cout<<"\n\t\t DANH SACH VUA XOA DAU THANH DANH SACH TRONG"<<endl;
							break;
						}
						case 2:{
							cout<<"\n	----------DANH SACH TRUOC KHI XOA CUOI-------------\n"<<endl;
							printf(head);
							deleteLast(head);
							cout<<"\n	----------DANH SACH SAU KHI XOA CUOI-------------"<<endl;
							printf(head);
							if(head==NULL)
								cout<<"\n\t\t DANH SACH VUA XOA CUOI THANH DANH SACH TRONG"<<endl;
							break;
						}
						case 3:{
							int manv;
							cout<<"\n\t NHAP MA NHAN VIEN MA BAN MUON XOA:	";
							cin>>manv;
							cout<<"\n	----------DANH SACH TRUOC KHI XOA 1 NHAN VIEN THEO MA SO NHAN VIEN-------------\n"<<endl;
							printf(head);
							deleteNode(head, a, manv);
							cout<<"\n	----------DANH SACH SAU KHI XOA 1 NHAN VIEN THEO MA SO NHAN VIEN-------------"<<endl;
							printf(head);
							if(head==NULL)
								cout<<"\n\t\t DANH SACH VUA XOA NHAN VIEN THANH DANH SACH TRONG"<<endl;
							break;
						}
					}
				}
				break;
			}	
			case 6:{
				return 0;
				break;
			}
			default:{
				system("cls");
				cout<<"\n\n\t\t\tLUA CHON KHONG HOP LE. VUI LONG LUA CHON LAI!!!";
				break;
			}
		}
	}
}
