// Jessica, Lucio, Viviane
// gcc -c cg3d.c
// gcc p2_1.c -o p2_1 cg3d.o -lm -lX11
#include "cg3d.h"

int p2_1(int argc, char ** argv) {
	int i;
  	palette * palheta;
  	bufferdevice * dispositivo;
  	window * janela;
  	object2d * obj2d;
	object3d * obj3d, *obj3dNovo;
	point3d *pp, *cp, *n, *r, *vu, *u, *v, *w, *novo;
	
	hmatrix3d *m = (hmatrix3d*)malloc(sizeof(hmatrix3d));
	
  	dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  	palheta = CreatePalette(2);  
  	SetColor(0,0,0,palheta);
  	SetColor(1,0,1,palheta);
  	
	obj3d=CreateObject3d(6);
	
	pp=SetPoint3d(0,0,1,1);
	cp=SetPoint3d(0, 0, -90,1);
	n = SetPoint3d(-5,-5,-5, 1);
	r = SetPoint3d(0, 0, 0, 1);
	vu = SetPoint3d(2, 1, -3, 1);

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
	DrawLine(&(obj2d->points[0]), &(obj2d->points[1]), janela, dispositivo, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[2]), janela, dispositivo, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[0]), janela, dispositivo, 1);
	
	DrawLine(&(obj2d->points[3]), &(obj2d->points[4]), janela, dispositivo, 1);
	DrawLine(&(obj2d->points[4]), &(obj2d->points[5]), janela, dispositivo, 1);
	DrawLine(&(obj2d->points[3]), &(obj2d->points[5]), janela, dispositivo, 1);
	
	DrawLine(&(obj2d->points[0]), &(obj2d->points[3]), janela, dispositivo, 1);
	DrawLine(&(obj2d->points[1]), &(obj2d->points[4]), janela, dispositivo, 1);
	DrawLine(&(obj2d->points[2]), &(obj2d->points[5]), janela, dispositivo, 1);

  	DumpX(dispositivo,palheta);
  	//DumpOpenGL(argc,argv,dispositivo,palheta);
  
  	return 0;
}

int main(int argc, char**argv){
	p2_1(argc, argv);
}