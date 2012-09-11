// Jessica, Lucio, Viviane
// gcc -c cg3d.c
// gcc p2_2.c -o p1_1 cg3d.o -lm -lX11
#include "cg3d.h"

int p2_1(int argc, char ** argv) {
	int i;
  	palette * palheta;
  	bufferdevice * dispositivo, *v1, *v2, *v3, *v4;
  	window * janela;
  	object2d * obj2d;
	object3d * obj3d, *obj2, *obj3, *obj4, *obj3dNovo;
	point3d *pp, *cp, *n, *r, *vu, *u, *v, *w, *novo;
	
	hmatrix3d *m = (hmatrix3d*)malloc(sizeof(hmatrix3d));
	
  	dispositivo = CreateBuffer(640,480); // cria um dispositivo
  	v1 = CreateBuffer(320, 240);
	v2 = CreateBuffer(320, 240);
	v3 = CreateBuffer(320, 240);
	v4 = CreateBuffer(320, 240);
	
  	palheta = CreatePalette(2);  
  	SetColor(0,0,0,palheta);
  	SetColor(1,0,1,palheta);
  	
	obj3d=CreateObject3d(6);
	obj3d=CreateObject3d(6);
	
	pp=SetPoint3d(0,0,1,1);
	cp=SetPoint3d(0, 0, -90,1);
	n = SetPoint3d(-5,-5,-5, 1);
//	r = SetPoint3d(14.5, 13.7, 18.3, 1);
	r = SetPoint3d(0, 0, 0, 1);
	vu = SetPoint3d(2, 1, -3, 1);
	//vu = SetPoint3d(4, -2, -2, 1);

	SetObject3d(SetPoint3d(10, 6, 0, 1), obj3d);
	SetObject3d(SetPoint3d(10, -6, 15, 1), obj3d);	
	SetObject3d(SetPoint3d(10, -6, -15, 1), obj3d);
	SetObject3d(SetPoint3d(-10, 6, 0, 1), obj3d);
	SetObject3d(SetPoint3d(-10, -6, 15, 1), obj3d);	
	SetObject3d(SetPoint3d(-10, -6, -15, 1), obj3d);
	
	w = Zv(*n);
	u = Xv(*vu, *n);
	v = Yv(*u, *w);

	m->a11 = u->x;
	m->a12 = u->y;
	m->a13 = u->z;
	m->a14 = r->x;

	m->a21 = v->x;
	m->a22 = v->y;
	m->a23 = v->z;
	m->a24 = r->y;
	
	m->a31 = w->x;
	m->a32 = w->y;
	m->a33 = w->z;
	m->a34 = r->z;

	obj3dNovo = CreateObject3d(6);
	
	novo = mudaBase(m, &(obj3d->points[0]));
	SetObject3d(novo, obj3dNovo);
	novo = mudaBase(m, &(obj3d->points[1]));
	SetObject3d(novo, obj3dNovo);
	novo = mudaBase(m, &(obj3d->points[2]));
	SetObject3d(novo, obj3dNovo);
	novo = mudaBase(m, &(obj3d->points[3]));
	SetObject3d(novo, obj3dNovo);
	novo = mudaBase(m, &(obj3d->points[4]));
	SetObject3d(novo, obj3dNovo);
	novo = mudaBase(m, &(obj3d->points[5]));
	
	obj2d = Projection(obj3dNovo, cp, pp);
	
  	janela = CreateWindow(-20.0,20.0,-20.0,20.0); // define uma janela de visualização
	//DrawObject(obj2d,janela,dispositivo);
	
	DrawLine(&(obj2d->points[0]), &(obj2d->points[1]), janela, v1, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[2]), janela, v1, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[0]), janela, v1, 1);
	
	DrawLine(&(obj2d->points[3]), &(obj2d->points[4]), janela, v1, 1);
	DrawLine(&(obj2d->points[4]), &(obj2d->points[5]), janela, v1, 1);
	DrawLine(&(obj2d->points[3]), &(obj2d->points[5]), janela, v1, 1);
	
	DrawLine(&(obj2d->points[0]), &(obj2d->points[3]), janela, v1, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[4]), janela, v1, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[5]), janela, v1, 1);

	obj2 = Rotate3dx(obj3dNovo, 45);
	obj3 = Rotate3dy(obj3dNovo, 45);
	obj4 = Rotate3dz(obj3dNovo, 45);
//	
	obj2d = Projection(obj2, cp, pp);
	DrawLine(&(obj2d->points[0]), &(obj2d->points[1]), janela, v2, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[2]), janela, v2, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[0]), janela, v2, 1);
	
	DrawLine(&(obj2d->points[3]), &(obj2d->points[4]), janela, v2, 1);
	DrawLine(&(obj2d->points[4]), &(obj2d->points[5]), janela, v2, 1);
	DrawLine(&(obj2d->points[3]), &(obj2d->points[5]), janela, v2, 1);
	
	DrawLine(&(obj2d->points[0]), &(obj2d->points[3]), janela, v2, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[4]), janela, v2, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[5]), janela, v2, 1);


//
	obj2d = Projection(obj3, cp, pp);
	DrawLine(&(obj2d->points[0]), &(obj2d->points[1]), janela, v3, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[2]), janela, v3, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[0]), janela, v3, 1);
	
	DrawLine(&(obj2d->points[3]), &(obj2d->points[4]), janela, v3, 1);
	DrawLine(&(obj2d->points[4]), &(obj2d->points[5]), janela, v3, 1);
	DrawLine(&(obj2d->points[3]), &(obj2d->points[5]), janela, v3, 1);
	
	DrawLine(&(obj2d->points[0]), &(obj2d->points[3]), janela, v3, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[4]), janela, v3, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[5]), janela, v3, 1);

//
	obj2d = Projection(obj4, cp, pp);
	DrawLine(&(obj2d->points[0]), &(obj2d->points[1]), janela, v4, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[2]), janela, v4, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[0]), janela, v4, 1);
	
	DrawLine(&(obj2d->points[3]), &(obj2d->points[4]), janela, v4, 1);
	DrawLine(&(obj2d->points[4]), &(obj2d->points[5]), janela, v4, 1);
	DrawLine(&(obj2d->points[3]), &(obj2d->points[5]), janela, v4, 1);
	
	DrawLine(&(obj2d->points[0]), &(obj2d->points[3]), janela, v4, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[4]), janela, v4, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[5]), janela, v4, 1);

  	CopyView2Device(dispositivo, v1, 0, 0);
	CopyView2Device(dispositivo, v2, 320, 0);
	CopyView2Device(dispositivo, v3, 0, 240);
	CopyView2Device(dispositivo, v4, 320, 240);
  	DumpX(dispositivo,palheta);
  	//DumpOpenGL(argc,argv,dispositivo,palheta);
  
  	return 0;
}


int main(int argc, char**argv){
	p2_1(argc, argv);
}
