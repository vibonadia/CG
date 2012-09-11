// Jessica, Lucio, Viviane
#include "cg3d.h"

bufferdevice * devGL;  // variáveis globais para facilitar a exibição com a glut
palette * palGL;
//Mundo 2D
void SetWorld2d(float xmin, float xmax, float ymin, float ymax) {
	XWMax = xmax;
 	XWMin = xmin;
 	YWMax = ymax;
 	YWMin = ymin;
}
//Mundo 3D
void SetWorld3d(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax) {
	XWMax = xmax;
 	XWMin = xmin;
 	YWMax = ymax;
 	YWMin = ymin;
	ZWMax = zmax;
	ZWMin = zmin;
}
//Ponto 2D
point2d * SetPoint2d(float x, float y, int color) {
  	point2d * pnt;
  
  	pnt = (point2d *) malloc(sizeof(point2d)); 
  	pnt->x = x;
  	pnt->y = y;
  	pnt->color = color;
  
  	return pnt;
}
//Ponto 3D
point3d * SetPoint3d(float x, float y, float z, int color) {
  	point3d * pnt;
  
  	pnt = (point3d *) malloc(sizeof(point3d)); 
  	pnt->x = x;
  	pnt->y = y;
	pnt->z = z;
  	pnt->color = color;
  
  	return pnt;
}
//Hpoint 2D
hpoint2d * SetHpoint2d(float x, float y, float w) {
  	hpoint2d * pnt;
  
  	pnt = (hpoint2d *) malloc(sizeof(hpoint2d)); 
  	pnt->x = x;
  	pnt->y = y;
  	pnt->w = w;
  
  	return pnt;
}
//Hpoint 3D
hpoint3d * SetHpoint3d(float x, float y, float z, float w) {
  	hpoint3d * pnt;
  
  	pnt = (hpoint3d *) malloc(sizeof(hpoint3d)); 
  	pnt->x = x;
  	pnt->y = y;
	pnt->z = z;
	pnt->w = w;
  
  	return pnt;
}
//Cria Objeto com pontos 2D
object2d * CreateObject2d(int numbers_of_points) {
  	object2d * ob;
 
  	ob = (object2d *) malloc(sizeof(object2d));
  	ob->numbers_of_points = 0;
  	ob->points = (point2d *) malloc(numbers_of_points*sizeof(point2d));
 
  	return ob;
}
//Cria Objeto com pontos 3D
object3d * CreateObject3d(int numbers_of_points) {
  	object3d * ob;
 
  	ob = (object3d *) malloc(sizeof(object3d));
  	ob->numbers_of_points = 0;
  	ob->points = (point3d *) malloc(numbers_of_points*sizeof(point3d));
 
  	return ob;
}
//Seta Objeto com pontos 2D
int SetObject2d(point2d * pnt, object2d * ob) {
  	ob->points[ob->numbers_of_points] = *pnt;
  	ob->numbers_of_points = ob->numbers_of_points + 1;

  	return 0;
}
//Seta Objeto com pontos 3D
int SetObject3d(point3d * pnt, object3d * ob) {
  	ob->points[ob->numbers_of_points] = *pnt;
  	ob->numbers_of_points = ob->numbers_of_points + 1;

  	return 0;
}
//Muda cor Objeto 2D
object2d * ChangeColor2d(object2d * ob, int color) {
  	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(ob->points[i].x,ob->points[i].y,color),oob);    
    }
    
  	return oob;  
}
//Muda cor Objeto 3D
object3d * ChangeColor3d(object3d * ob, int color) {
  	object3d * oob;
  	int i;
  
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(ob->points[i].x,ob->points[i].y, ob->points[i].z,color),oob);    
    }
    
  	return oob;  
}

//Cores
palette * CreatePalette(int numbers_of_colors) {
  	palette * pal;

  	pal = (palette *) malloc(sizeof(palette));
  	pal->numbers_of_colors = 0;
  	pal->colors = (ColorValues *) malloc(numbers_of_colors*sizeof(ColorValues));
  
  	return pal;
}
//Cores
int SetColor(float red, float green, float blue, palette * pal) {
  	pal->colors[pal->numbers_of_colors].red = red;
  	pal->colors[pal->numbers_of_colors].green = green;
  	pal->colors[pal->numbers_of_colors].blue = blue;
  	pal->numbers_of_colors = pal->numbers_of_colors + 1;

  	return 0;
}
//Cores
ColorValues * GetColor(int value, palette * pal) {
 	ColorValues * color;
 
 	color = (ColorValues *) malloc(sizeof(ColorValues)); 
 	color->red = pal->colors[value].red;
 	color->green = pal->colors[value].green;
 	color->blue = pal->colors[value].blue; 
 
 	return color;
}
//Buffer 2D
bufferdevice * CreateBuffer(int maxx, int maxy) {
  	bufferdevice * dev;
  
  	dev = (bufferdevice *) malloc(sizeof(bufferdevice));
  	dev->MaxX = maxx;
  	dev->MaxY = maxy;
  	dev->buffer = (int *) malloc(maxx*maxy*sizeof(int));


  	return dev;
}
//Janela 2D
window * CreateWindow(float xmin, float xmax, float ymin, float ymax) {
  	window * win;

  	win = (window *) malloc(sizeof(window));
  	win->xmin = xmin;
  	win->xmax = xmax;
  	win->ymin = ymin;
  	win->ymax = ymax;
  
  	return win;
}
//Circulo
object2d * Circulo(point2d * centro, float raio){
	object2d * oob;
	oob = CreateObject2d(64);
	int i;	
	float angle,x,y; 
  	for(i=0;i<64;i++) {
		angle = (2*PI*i)/64;
		x=raio*cos(angle)+centro->x;
		y=raio*sin(angle)+centro->y;
    	SetObject2d(SetPoint2d(x, y, centro->color),oob);    
    }
    
  	return oob;
}
//Projetando um ponto 3d no plano 2d Versão da Vivi
//Recebe um objeto3d, pontoCP, pontoPP 
object2d * Projection(object3d * ob, point3d * cp, point3d * pp){
	object2d * oob;
	float x, y;
  	int i;
	float lambda;
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
		x = ob->points[i].x * ((pp->z - cp->z)/(ob->points[i].z - cp->z));
		y = ob->points[i].y * ((pp->z - cp->z)/(ob->points[i].z - cp->z));
    	SetObject2d(SetPoint2d(x, y,ob->points[i].color),oob);    
/*Versão do Boi
		lambda= -(ob->points[i].z)/(pp->z - cp->z);
		x=(ob->points[i].x/lambda);
		y=(ob->points[i].y/lambda);
    	SetObject2d(SetPoint2d(x, y,ob->points[i].color),oob);    
*/
    }
    
  	return oob;
}
//Do Universo para o Normalizado 2D
point2d * Sru2Srn(point2d * ponto, window * janela) {
  	point2d * np;

  	np = (point2d *) malloc(sizeof(point2d));
  	np->x = (ponto->x - janela->xmin)/(janela->xmax - janela->xmin);
  	np->y = (ponto->y - janela->ymin)/(janela->ymax - janela->ymin);
  	np->color = ponto->color;
  
  	return np;  
}
//Do Normalizado 2D para o Dispositivo 2D
point2d * Srn2Srd(point2d * ponto, bufferdevice * dev) {
  	point2d * dpt;

  	dpt = (point2d *) malloc(sizeof(point2d));
  	dpt->x = round((ponto->x)*(dev->MaxX - 1));
  	dpt->y = round((ponto->y)*(dev->MaxY - 1));
  	dpt->color = ponto->color;
 
  	return dpt;
}
//Verifica se o ponto está dentro da Janela
int InWin(point2d * pt, window * win) {
  	if ((pt->x >= win->xmin)&&(pt->x <= win->xmax)&&
		(pt->y >= win->ymin)&&(pt->y <= win->ymax))
 		return 1;
  	else
 		return 0;
}
//Intersecção entre dois pontos no eixo X
point2d * InterX(point2d * p1, point2d * p2, float x) {
 	float a , b, aux;
 
 	if (p2->x - p1->x) {
   		a = (p2->y - p1->y)/(p2->x - p1->x);
   		b = p1->y - a*p1->x;
   		aux = a*x+b;
   	}
 	else
		aux = 1000000.0;  
 
 	return SetPoint2d(x,aux,p1->color);
}
//Intersecção entre dois pontos no eixo Y
point2d * InterY(point2d * p1, point2d * p2, float y) {
 	float a , b, aux;

 	if (p2->x - p1->x) {
   		a = (p2->y - p1->y)/(p2->x - p1->x);
   		b = p1->y - a*p1->x;
   		if (a)
			aux = (y-b)/a;
   		else
 			aux = 1000000.0;
   	}else
 		aux = p2->x;
 
 	return SetPoint2d(aux,y,p1->color);
}
//Desenha reta entre 2 pontos 2D
int DrawLine(point2d * p1, point2d * p2, window * win, bufferdevice * dev, int color) {
  	float a, b;
  	int i, j, aux;
  	point2d * pn1, * pd1, * pn2, * pd2;
  
  	pn1 = Sru2Srn(p1,win);
  	pd1 = Srn2Srd(pn1,dev);
  	pn2 = Sru2Srn(p2,win);
  	pd2 = Srn2Srd(pn2,dev);
  
	if (pd1->y > pd2->y) {
  		aux = pd1->y;
  		pd1->y = pd2->y;
  		pd2->y = aux;
  		aux = pd1->x;
  		pd1->x = pd2->x;
  		pd2->x = aux;
  	}   
    	
  	if (pd1->x > pd2->x) {
    	aux = pd1->x;
    	pd1->x = pd2->x;
    	pd2->x = aux;
    	aux = pd1->y;
    	pd1->y = pd2->y;
    	pd2->y = aux;
    }
   	i = pd1->x;
   	j = pd1->y;
   
   	if (pd1->x == pd2->x) {
     	while (j < pd2->y) {
       		dev->buffer[(dev->MaxY - j - 1) * dev->MaxX + i] = color;
       		j++;
       	}
    }
	else {
     	a = (pd2->y - pd1->y)/(pd2->x - pd1->x);
     	b = pd1->y - a*pd1->x;
     	while (i < pd2->x) {
       		dev->buffer[(dev->MaxY - j - 1) * dev->MaxX + i] = color;
       		aux = j;
       		j = round(a*(++i) + b);
       
       		if (j > aux) {
	 			while (aux < j) {
	   				dev->buffer[(dev->MaxY - aux - 1) * dev->MaxX + i] = color; 
	   				aux++;
	   			}
         	}
       		if (j < aux) {
	 			while (aux > j) { 
	   				dev->buffer[(dev->MaxY - aux - 1) * dev->MaxX + i] = color;
	   				aux--;
	   			}
         	}
        
       	}
	}

  	return 0;
}
//Desenha objeto, somente 2D
int DrawObject(object2d * ob, window * win, bufferdevice * dev) {
  	int i;
  	float aux;
  	point2d * p1, * p2, * paux;
  
  	for(i=0;i<ob->numbers_of_points;i++) {
    	p1 = SetPoint2d(ob->points[i].x,ob->points[i].y,ob->points[i].color);
    	p2 = SetPoint2d(ob->points[(i+1)%ob->numbers_of_points].x,ob->points[(i+1)%ob->numbers_of_points].y,ob->points[(i+1)%ob->numbers_of_points].color);
    
    	if (p1->y > p2->y) {
      		aux = p1->y;
      		p1->y = p2->y;
      		p2->y = aux;
      		aux = p1->x;
      		p1->x = p2->x;
      		p2->x = aux;
      	}   
    	if ((p1->y < win->ymax)&&(p2->y > win->ymax)) {
      		paux = InterY(p1,p2,win->ymax);
      		if (InWin(paux,win)) {
        		p2 = paux;
        	} 
      	}
    	if ((p1->y < win->ymin)&&(p2->y > win->ymin)) {
      		paux = InterY(p1,p2,win->ymin);
      		if (InWin(paux,win)) {
        		p1 = paux;
        	} 
      	}

    	if (p1->x > p2->x) {
      		aux = p1->y;
      		p1->y = p2->y;
      		p2->y = aux;
      		aux = p1->x;
      		p1->x = p2->x;
      		p2->x = aux;
      	}      
    	if ((p1->x < win->xmax)&&(p2->x > win->xmax)) {
      		paux = InterX(p1,p2,win->xmax);
      		if (InWin(paux,win)) {
        		p2 = paux;
        	} 
      	}
    	if ((p1->x < win->xmin)&&(p2->x > win->xmin)) {
      		paux = InterX(p1,p2,win->xmin);
      		if (InWin(paux,win)) {
        		p1 = paux;
        	} 
      	}

    	if ((InWin(p1,win))&&(InWin(p2,win))){
 			DrawLine(p1,p2,win,dev,p1->color);
		}
    }

  	return 0;
}
//Preenchimento 2D
int FillObject(bufferdevice * buf, int color) {
	int m, n, i = 0, j, par = 0;  

  	for(m=0;m<buf->MaxY;m++) {
    	for(n=0;n<buf->MaxX;n++) {
      		if ((buf->buffer[m*buf->MaxX+n]!=0)&&(buf->buffer[m*buf->MaxX+n+1]==0)&&(par)) {
				par = 0;
				for(j=i;j<n;j++)
 					buf->buffer[m*buf->MaxX+j] = color;
			} 
      		if ((buf->buffer[m*buf->MaxX+n]!=0)&&(buf->buffer[m*buf->MaxX+n+1]==0)&&(!par)){
				par = 1;
				i = n;
        	}
      	}
	}

  	return 0;
}
//Preenchimento 2D
int Fill(object2d * ob, window * win, bufferdevice * dev, int color) {

  	bufferdevice * temp = CreateBuffer(dev->MaxX,dev->MaxY);  
  	DrawObject(ob,win,temp);  
  	FillObject(temp,color);
  	CopyBuffer2Device(temp,dev);
  
  	return 0;
}
//Copia de um Buffer para Outro
void CopyBuffer2Device(bufferdevice * buf, bufferdevice * dev) {
  	int m, n;

  	for(m=0;m<buf->MaxY;m++) {
    	for(n=0;n<buf->MaxX;n++) {
      		if (buf->buffer[m*buf->MaxX+n] != 0)
 				dev->buffer[m*dev->MaxX+n] = buf->buffer[m*buf->MaxX+n];
      	}
    }  
}
//Copia de um Buffer para outro, usando deslocamentos
void CopyView2Device(bufferdevice * dev, bufferdevice * view, int deslocaX, int deslocaY){
 	int m, n;
  	int x, y;
  	x = deslocaX;
  	y = deslocaY;
  	for(m = 0; m < view->MaxY; m++) {
    	for(n = 0; n < view->MaxX; n++) {
      		dev->buffer[((m + y) * dev->MaxX) + (n + x)] = view->buffer[m * view->MaxX + n];
      	}
    }  
}

//Rotação em 2D
object2d * Rotate2dz(object2d * ob, float theta) {
  	object2d * oob;
  	int i;
  	float phi;
  
  	phi = (theta*PI)/180.0;
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d((ob->points[i].x)*cos(phi)-(ob->points[i].y)*sin(phi),(ob->points[i].x)*sin(phi)+(ob->points[i].y)*cos(phi),ob->points[i].color),oob);    
    }
    
  	return oob;
}
//Rotação em 3D em Z- feito =D
object3d * Rotate3dz(object3d * ob, float theta) {
  	object3d * oob;
  	int i;
  	float phi;
  
  	phi = (theta*PI)/180.0;
  	oob = CreateObject3d(ob->numbers_of_points); 
  	
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(
			(ob->points[i].x)*cos(phi)-(ob->points[i].y)*sin(phi),
			(ob->points[i].x)*sin(phi)+(ob->points[i].y)*cos(phi),
			ob->points[i].z,
			ob->points[i].color),
    	oob);    
    }
    
  	return oob;
}
//Rotação em 3D em X- feito?
object3d * Rotate3dx(object3d * ob, float theta) {
  	object3d * oob;
  	int i;
  	float phi;
  
  	phi = (theta*PI)/180.0;
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(
			ob->points[i].x,
			(ob->points[i].y)*cos(phi)-(ob->points[i].z)*sin(phi),
			(ob->points[i].y)*sin(phi) + (ob->points[i].z)*cos(phi),
			ob->points[i].color),
    	oob);    
    }
    
  	return oob;
}
//Rotação em 3D em Y- feito?
object3d * Rotate3dy(object3d * ob, float theta) {
  	object3d * oob;
  	int i;
  	float phi;
  
  	phi = (theta*PI)/180.0;
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(
			(ob->points[i].x)*cos(phi) + (ob->points[i].y)*sin(phi),
			ob->points[i].y,
			-(ob->points[i].x)*sin(phi) + (ob->points[i].z)*cos(phi),
			ob->points[i].color),
    	oob);    
    }
  	return oob;
}

//Translação em 2D
object2d * Translate2d(object2d * ob, float x, float y) {
  	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(ob->points[i].x + x,ob->points[i].y + y,ob->points[i].color),oob);    
    }
    
  	return oob;
}
//Translação em 3D
object3d * Translate3d(object3d * ob, float x, float y, float z) {
  	object3d * oob;
  	int i;
  
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(ob->points[i].x + x,ob->points[i].y + y,ob->points[i].z + z,ob->points[i].color),oob);    
    }
    
  	return oob;
}

//Escalonamento em 2D
object2d * Scale2d(object2d * ob, float sx, float sy) {
  	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(sx*(ob->points[i].x),sy*(ob->points[i].y),ob->points[i].color),oob);    
  	}
    
  	return oob;  
}
//Escalonamento em 3D
object3d * Scale3d(object3d * ob, float sx, float sy, float sz) {
  	object3d * oob;
  	int i;
  
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(sx*(ob->points[i].x),sy*(ob->points[i].y),sz*(ob->points[i].z), ob->points[i].color),oob);    
  	}
    
  	return oob;  
}
//Espelhamento 2D em X
object2d * Mirror2dx(object2d * ob){
	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(-1*(ob->points[i].x),1*(ob->points[i].y),ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Espelhamento 3D em X
object3d * Mirror3dx(object3d * ob){
	object3d * oob;
  	int i;
  
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(-1*(ob->points[i].x),1*(ob->points[i].y),1*(ob->points[i].z), ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Espelhamento 2D em Y
object2d * Mirror2dy(object2d * ob){
	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(1*(ob->points[i].x),-1*(ob->points[i].y),ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Espelhamento 3D em Y
object3d * Mirror3dy(object3d * ob){
	object3d * oob;
  	int i;
  
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(1*(ob->points[i].x),-1*(ob->points[i].y),1*(ob->points[i].z), ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Espelhamento 3D em Z
object3d * Mirror3dz(object3d * ob){
	object3d * oob;
  	int i;
  
  	oob = CreateObject3d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject3d(SetPoint3d(1*(ob->points[i].x),1*(ob->points[i].y),-1*(ob->points[i].z), ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Cisalhamento 2D em X
object2d * Shearing2dx(object2d * ob, float she){
	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(she+(ob->points[i].x),1*(ob->points[i].y),ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Cisalhamento 2D em Y
object2d * Shearing2dy(object2d * ob, float she){
	object2d * oob;
  	int i;
  
  	oob = CreateObject2d(ob->numbers_of_points); 
  	for(i=0;i<ob->numbers_of_points;i++) {
    	SetObject2d(SetPoint2d(1*(ob->points[i].x),she+(ob->points[i].y),ob->points[i].color),oob);    
  	}
    
  	return oob;
}
//Converte point2d para hpoind2d ------ AQUI!!!!!!!!!!!!!!!!!!!!!!!!1
hpoint2d * Point2d2Hpoint2d(point2d * point){
	hpoint2d * pt;
	pt=SetHpoint2d(point->x, point->y, 1);

	return pt;
}
//Converte point3d para hpoint3d
hpoint3d * Point3d2Hpoint3d(point3d * point){
	hpoint3d * pt;
	pt=SetHpoint3d(point->x, point->y, point->z, 1);

	return pt;
}
//Converte hpoint2d para poind2d
point2d * Hpoint2d2Point2d(hpoint2d * hpoint){
	point2d * pt;
	pt=SetPoint2d(hpoint->x, hpoint->y, 2);

	return pt;
}
//Converte hpoint3d para point3d
point3d * Hpoint3d2Point3d(hpoint3d * hpoint){
	point3d * pt;
	pt=SetPoint3d(hpoint->x, hpoint->y, hpoint->z, 2);

	return pt;
}

//Ponto Homegênio 2D - Tranformação Linear	Matriz 3x3 * 3x1
hpoint2d * LinearTransf2d(hmatrix2d * m, hpoint2d * p) {
  	hpoint2d * pt;
  
  	pt = (hpoint2d *) malloc(sizeof(hpoint2d));
  
  	pt->x = m->a11*p->x + m->a12*p->y + m->a13*p->w;
  	pt->y = m->a21*p->x + m->a22*p->y + m->a23*p->w;
  	pt->w = m->a31*p->x + m->a32*p->y + m->a33*p->w;
  
  	return pt;
}
//Ponto Homegênio 3D - Tranformação Linear Matriz 4x4 * 4x1
hpoint3d * LinearTransf3d(hmatrix3d * m, hpoint3d * p) {
  	hpoint3d * pt;
  
  	pt = (hpoint3d *) malloc(sizeof(hpoint3d));
  
  	pt->x = m->a11*p->x + m->a12*p->y + m->a13*p->z + m->a14*p->w;
  	pt->y = m->a21*p->x + m->a22*p->y + m->a23*p->z + m->a24*p->w;
  	pt->z = m->a31*p->x + m->a32*p->y + m->a33*p->z + m->a34*p->w;
  	pt->w = m->a41*p->x + m->a42*p->y + m->a43*p->z + m->a44*p->w;
  	return pt;
}

//Ponto 2D Homogênio - Multiplica duas matrizes 3x3
hmatrix2d * ComposeMatrix2d(hmatrix2d * m1, hmatrix2d * m2) {
  	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = m1->a11*m2->a11 + m1->a12*m2->a21 + m1->a13*m2->a31;
  	m->a12 = m1->a11*m2->a12 + m1->a12*m2->a22 + m1->a13*m2->a32;
  	m->a13 = m1->a11*m2->a13 + m1->a12*m2->a23 + m1->a13*m2->a33;
  
  	m->a21 = m1->a21*m2->a11 + m1->a22*m2->a21 + m1->a23*m2->a31;
  	m->a22 = m1->a21*m2->a12 + m1->a22*m2->a22 + m1->a23*m2->a32;
  	m->a23 = m1->a21*m2->a13 + m1->a22*m2->a23 + m1->a23*m2->a33;
  
  	m->a31 = m1->a31*m2->a11 + m1->a32*m2->a21 + m1->a33*m2->a31;
  	m->a32 = m1->a31*m2->a12 + m1->a32*m2->a22 + m1->a33*m2->a32;
  	m->a33 = m1->a31*m2->a13 + m1->a32*m2->a23 + m1->a33*m2->a33;
  
  	return m;
}
//Ponto 3D Homogênio - Multiplica duas matrizes 4x4
hmatrix3d * ComposeMatrix3d(hmatrix3d * m1, hmatrix3d * m2) {
  	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = m1->a11*m2->a11 + m1->a12*m2->a21 + m1->a13*m2->a31 + m1->a14*m2->a41;
  	m->a12 = m1->a11*m2->a12 + m1->a12*m2->a22 + m1->a13*m2->a32 + m1->a14*m2->a42;
  	m->a13 = m1->a11*m2->a13 + m1->a12*m2->a23 + m1->a13*m2->a33 + m1->a14*m2->a43;
	m->a14 = m1->a11*m2->a14 + m1->a12*m2->a24 + m1->a13*m2->a34 + m1->a14*m2->a44;
  
  	m->a21 = m1->a21*m2->a11 + m1->a22*m2->a21 + m1->a23*m2->a31 + m1->a24*m2->a41;
  	m->a22 = m1->a21*m2->a12 + m1->a22*m2->a22 + m1->a23*m2->a32 + m1->a24*m2->a42;
  	m->a23 = m1->a21*m2->a13 + m1->a22*m2->a23 + m1->a23*m2->a33 + m1->a24*m2->a43;
	m->a24 = m1->a21*m2->a14 + m1->a22*m2->a24 + m1->a23*m2->a34 + m1->a24*m2->a44;  

  	m->a31 = m1->a31*m2->a11 + m1->a32*m2->a21 + m1->a33*m2->a31 + m1->a34*m2->a41;
  	m->a32 = m1->a31*m2->a12 + m1->a32*m2->a22 + m1->a33*m2->a32 + m1->a34*m2->a42;
  	m->a33 = m1->a31*m2->a13 + m1->a32*m2->a23 + m1->a33*m2->a33 + m1->a34*m2->a43;
	m->a34 = m1->a31*m2->a14 + m1->a32*m2->a24 + m1->a33*m2->a34 + m1->a34*m2->a44;
  	
	m->a41 = m1->a41*m2->a11 + m1->a42*m2->a21 + m1->a43*m2->a31 + m1->a44*m2->a41;
  	m->a42 = m1->a41*m2->a12 + m1->a42*m2->a22 + m1->a43*m2->a32 + m1->a44*m2->a42;
  	m->a43 = m1->a41*m2->a13 + m1->a42*m2->a23 + m1->a43*m2->a33 + m1->a44*m2->a43;
	m->a44 = m1->a41*m2->a14 + m1->a42*m2->a24 + m1->a43*m2->a34 + m1->a44*m2->a44;
  
  	return m;
}
//Matriz de Rotação 2D - Sobre eixo Z
hmatrix2d * SetRotMatrix2d(float th) {
  	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = cos((th*PI)/180.0); m->a12 = (-1.0)*sin((th*PI)/180.0); m->a13 = 0.0;
  	m->a21 = sin((th*PI)/180.0); m->a22 = cos((th*PI)/180.0);        m->a23 = 0.0;
  	m->a31 = 0.0;                m->a32 = 0.0;                       m->a33 = 1.0;
  
  	return m;
}
//Matriz de Rotação 3D - Sobre eixo Z
hmatrix3d * SetRotMatrix3dz(float th) {
  	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = cos((th*PI)/180.0); m->a12 = (-1.0)*sin((th*PI)/180.0); m->a13 = 0.0; m->a14=0.0;
  	m->a21 = sin((th*PI)/180.0); m->a22 = cos((th*PI)/180.0);        m->a23 = 0.0; m->a24=0.0;
  	m->a31 = 0.0;                m->a32 = 0.0;                       m->a33 = 1.0; m->a34=0.0;
	m->a41 = 0.0;				 m->a42 = 0.0;						 m->a43 = 0.0; m->a44=1.0;
  
  	return m;
}
//Matriz de Rotação 3D - Sobre eixo X
hmatrix3d * SetRotMatrix3dx(float th) {
  	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = 1.0; m->a12 = 0.0; 				m->a13 = 0.0; 						m->a14=0.0;
  	m->a21 = 0.0; m->a22 = cos((th*PI)/180.0);  m->a23 = (-1.0)*sin((th*PI)/180.0); m->a24=0.0;
  	m->a31 = 0.0; m->a32 = sin((th*PI)/180.0);  m->a33 = cos((th*PI)/180.0);        m->a34=0.0;
	m->a41 = 0.0; m->a42 = 0.0;					m->a43 = 0.0; 						m->a44=1.0;
  
  	return m;
}
//Matriz de Rotação 3D - Sobre eixo Y
hmatrix3d * SetRotMatrix3dy(float th) {
  	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = cos((th*PI)/180.0); m->a12 = 0.0; m->a13 = sin((th*PI)/180.0); m->a14=0.0;
  	m->a21 = 0.0;                m->a22 = 1.0; m->a23 = 0.0;                m->a24=0.0;
  	m->a31 = (-1.0)*sin((th*PI)/180.0); m->a32 = cos((th*PI)/180.0); m->a33 = 1.0; m->a34=0.0;
	m->a41 = 0.0;				 m->a42 = 0.0;						 m->a43 = 0.0; m->a44=1.0;
  
  	return m;
}
//Matriz de Escalonamento 2D
hmatrix2d * SetSclMatrix2d(float sx, float sy) {
  	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = sx;  m->a12 = 0.0;  m->a13 = 0.0;
  	m->a21 = 0.0; m->a22 = sy;   m->a23 = 0.0;
  	m->a31 = 0.0; m->a32 = 0.0;  m->a33 = 1.0;
  
  	return m;
}
//Matriz de Escalonamento 3D
hmatrix3d * SetSclMatrix3d(float sx, float sy, float sz) {
  	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = sx ; m->a12 = 0.0;  m->a13 = 0.0; m->a14=0.0; 
  	m->a21 = 0.0; m->a22 = sy ;  m->a23 = 0.0; m->a24=0.0;
  	m->a31 = 0.0; m->a32 = 0.0;  m->a33 = sz ; m->a34=0.0;
	m->a41 = 0.0; m->a42 = 0.0;  m->a43 = 0.0; m->a44=1.0;
  
  	return m;
}
//Pontos 2D Homogênio - Translação
hmatrix2d * SetSftMatrix2d(float dx, float dy) {
  	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = 1.0;  m->a12 = 0.0;  m->a13 = dx;
  	m->a21 = 0.0;  m->a22 = 1.0;  m->a23 = dy;
  	m->a31 = 0.0;  m->a32 = 0.0;  m->a33 = 1.0;
  
  	return m;  
}
//Pontos 3D Homogênio - Translação
hmatrix3d * SetSftMatrix3d(float dx, float dy, float dz) {
  	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = 1.0;  m->a12 = 0.0;  m->a13 = 0.0; m->a14 = dx;
  	m->a21 = 0.0;  m->a22 = 1.0;  m->a13 = 0.0; m->a24 = dy;
  	m->a31 = 0.0;  m->a32 = 0.0;  m->a13 = 1.0; m->a34 = dz;
	m->a41 = 0.0;  m->a42 = 0.0;  m->a43 = 0.0; m->a44 = 1.0;
  
  	return m;  
}
//Mirror
hmatrix2d * SetMirMatrix2dx(){
	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = -1.0;  m->a12 = 0.0;  m->a13 = 0.0;
  	m->a21 = 0.0;   m->a22 = 1.0;  m->a23 = 0.0;
  	m->a31 = 0.0;   m->a32 = 0.0;  m->a33 = 1.0;
  
  	return m;
}
hmatrix2d * SetMirMatrix2dy(){
	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = 1.0;   m->a12 = 0.0;    m->a13 = 0.0;
  	m->a21 = 0.0;   m->a22 = -1.0;   m->a23 = 0.0;
  	m->a31 = 0.0;   m->a32 = 0.0;    m->a33 = 1.0;
  
  	return m;
}
hmatrix3d * SetMirMatrix3dx(){
	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = -1.0;  m->a12 = 0.0;  m->a13 = 0.0; m->a14 = 0.0;
  	m->a21 = 0.0;  m->a22 = 1.0;  m->a13 = 0.0; m->a24 = 0.0;
  	m->a31 = 0.0;  m->a32 = 0.0;  m->a13 = 1.0; m->a34 = 0.0;
	m->a41 = 0.0;  m->a42 = 0.0;  m->a43 = 0.0; m->a44 = 1.0;
  
  	return m;
}
hmatrix3d * SetMirMatrix3dy(){
	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = 1.0;  m->a12 = 0.0;  m->a13 = 0.0; m->a14 = 0.0;
  	m->a21 = 0.0;  m->a22 = -1.0;  m->a13 = 0.0; m->a24 = 0.0;
  	m->a31 = 0.0;  m->a32 = 0.0;  m->a13 = 1.0; m->a34 = 0.0;
	m->a41 = 0.0;  m->a42 = 0.0;  m->a43 = 0.0; m->a44 = 1.0;
  
  	return m;
}
hmatrix3d * SetMirMatrix3dz(){
	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = 1.0;  m->a12 = 0.0;  m->a13 = 0.0; m->a14 = 0.0;
  	m->a21 = 0.0;  m->a22 = 1.0;  m->a13 = 0.0; m->a24 = 0.0;
  	m->a31 = 0.0;  m->a32 = 0.0;  m->a13 = -1.0; m->a34 = 0.0;
	m->a41 = 0.0;  m->a42 = 0.0;  m->a43 = 0.0; m->a44 = 1.0;
  
  	return m;
}
//Mudança de Base 2D
hmatrix2d * SetMudMatrix2d(point2d * u, point2d* v, point2d * r){
	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = u->x;   m->a12 = u->y;    m->a13 = -(r->x);
  	m->a21 = v->x;   m->a22 = v->y;   m->a23 = -(r->y);
  	m->a31 = 0.0;   m->a32 = 0.0;    m->a33 = 1.0;
  
  	return m;
}
//Mudança de Base 3D
hmatrix3d * SetMudMatrix3d(point3d * u, point3d * v, point3d * w, point3d * r){
	hmatrix3d * m;

  	m = (hmatrix3d *) malloc(sizeof(hmatrix3d));
  
  	m->a11 = u->x;  m->a12 = u->y;  m->a13 = u->z; m->a14 =-(r->x);
  	m->a21 = v->x;  m->a22 = v->y;  m->a13 = v->z; m->a24 =-(r->y);
  	m->a31 = w->x;  m->a32 = w->y;  m->a13 = w->z; m->a34 =-(r->z);
	m->a41 = 0.0;  m->a42 = 0.0;  m->a43 = 0.0; m->a44 = 1.0;
  
  	return m;
}

point3d * mudaBase(hmatrix3d * m, point3d * velho){
	point3d * novo = (point3d *)malloc(sizeof(point3d));
	
	novo->x = (m->a11 * velho->x) + (m->a12 * velho->y) + (m->a13 * velho->z) + (m->a14);
	novo->y = (m->a21 * velho->x) + (m->a22 * velho->y) + (m->a23 * velho->z) + (m->a24);
	novo->z = (m->a31 * velho->x) + (m->a32 * velho->y) + (m->a33 * velho->z) + (m->a34);
	
	return novo;
}

//Cisalhamento
hmatrix2d * SetSheMatrix2dx(float she){
	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = she;   m->a12 = 0.0;    m->a13 = 0.0;
  	m->a21 = 0.0;   m->a22 = 1.0;   m->a23 = 0.0;
  	m->a31 = 0.0;   m->a32 = 0.0;    m->a33 = 1.0;
  
  	return m;
}
hmatrix2d * SetSheMatrix2dy(float she){
	hmatrix2d * m;

  	m = (hmatrix2d *) malloc(sizeof(hmatrix2d));
  
  	m->a11 = 1.0;   m->a12 = 0.0;    m->a13 = 0.0;
  	m->a21 = she;   m->a22 = -1.0;   m->a23 = 0.0;
  	m->a31 = 0.0;   m->a32 = 0.0;    m->a33 = 1.0;
  
  	return m;
}
//RGB para HSV
ColorValues * RGB2HSV(ColorValues * rgb) {
  	float r, g, b, h, s, v, max, min;
  	ColorValues * hsv;
  
  	r = rgb->red;
  	g = rgb->green;
  	b = rgb->blue;
  
  	if ((r>=g)&&(r>=b))
		max = r;
  	if ((g>=r)&&(g>=b)) 
		max = g;
  	if ((b>=g)&&(b>=r)) 
		max = b;
  
  	if ((r<=g)&&(r<=b)) 
		min = r;
  	if ((g<=r)&&(g<=b)) min = g;
  	if ((b<=g)&&(b<=r)) min = b;
  
  	v = max;
  
  	s = (max-min)/max;
  
  	if ((max==r)&&(g>=b)) h = 60.0 * (g-b)/(max-min);
  	if ((max==r)&&(g<b)) h = 60.0 * (g-b)/(max-min) + 360;
  	if (max==g) h = 60.0 * (b-r)/(max-min) + 120;
  	if (max==b) h = 60.0 * (r-g)/(max-min) + 240; 
  
  	hsv = (ColorValues *) malloc(sizeof(ColorValues));
  
  	hsv->red = h;
  	hsv->green = s;
  	hsv->blue = v;
  
  	return hsv;
}
//HSV para RGB
ColorValues * HSV2RGB(ColorValues * hsv) {
  	float r, g, b, h, s, v, f, p, q, t;
  	ColorValues * rgb;
  	int hi;
  
  	h = hsv->red;
  	s = hsv->green;
  	v = hsv->blue; 
  
  	rgb = (ColorValues *) malloc(sizeof(ColorValues));
  
  	if (s==0) {
    	rgb->red = v;
    	rgb->green = v;
    	rgb->blue = v;
    }else {
    	hi = ((int)floor(h/60.0)) % 6;
    	f = h/60.0 - hi;
    	p = v*(1.0-s);
    	q = v*(1.0-f*s);
    	t = v*(1.0-(1.0-f)*s);
    	if (hi==0) {
      		rgb->red = v;
      		rgb->green = t;
      		rgb->blue = p;
      	}
    	if (hi==1) {
      		rgb->red = q;
      		rgb->green = v;
      		rgb->blue = p;
      	}
    	if (hi==2) {
      		rgb->red = p;
      		rgb->green = v;
      		rgb->blue = t;
      	}
    	if (hi==3) {
      		rgb->red = p;
      		rgb->green = q;
      		rgb->blue = v;
      	}
    	if (hi==4) {
      		rgb->red = t;
      		rgb->green = p;
      		rgb->blue = v;
      	}
    	if (hi==5) {
      		rgb->red = v;
      		rgb->green = p;
      		rgb->blue = q;
      	}       
	}
  
  	return rgb;
}
//Joga pra Tela - Recebe um Buffer e uma Paleta de Cores
int DumpX(bufferdevice * dev, palette * pal) {
  	Display 			  * display;
  	XImage                * ximage;
  	Window                window;
  	XEvent                an_event;
  	GC                    gc;
  	Visual                * visual;
  	XGCValues             values;
  	int                   m, n, screen, dplanes;
  	int                   width, height, ret = 1;
  	ColorValues           * cor;
  
  	width = dev->MaxX;
  	height = dev->MaxY; 

  	if ((display = XOpenDisplay(NULL)) == NULL)
		ret = 0;
  	else {  
    	screen = DefaultScreen(display);
    	dplanes = DisplayPlanes(display,screen);   
    	visual = XDefaultVisual(display,screen);
  
    	if (!(window=XCreateSimpleWindow(display,RootWindow(display,screen),0,0,width,height,1,BlackPixel(display,screen),WhitePixel(display,screen))))
			ret = 0;
    	else {
      		XSelectInput(display, window, EventMask);
      		gc = XCreateGC(display, window, 0, &values);
      		XMapWindow(display,window);
      		XSync(display,False);
  			ximage = XCreateImage(display,visual,dplanes,ZPixmap,0,malloc(width*height*sizeof(int)),width,height,8,0);

      		for(m=0;m<height;m++) {
        		for(n=0;n<width;n++) {
          			cor = GetColor(dev->buffer[m*width+n],pal);
          			ximage -> data[(m*4)*width+n*4] = (char) round((cor->blue)*255);
          			ximage -> data[(m*4)*width+n*4+1] = (char) round((cor->green)*255);
          			ximage -> data[(m*4)*width+n*4+2] = (char) round((cor->red)*255);
          			ximage -> data[(m*4)*width+n*4+3] = (char) 0;
          		}
        	}

      		XPutImage(display,window,gc,ximage,0,0,0,0,width,height);

      		sleep(50);
      	}
	}
 
  	return ret;
}

//******************Plano de Observacao (Xv, Yv, Zv)******************//
//calcula o produto vetorial entre dois vetores
point3d prodVetorial(point3d a, point3d b){
  point3d v;
  v.x = (a.y * b.z) - (b.y * a.z);
  v.y = (b.x * a.z) - (b.z * a.x);
  v.z = (a.x * b.y) - (a.y * b.x);
  return v;
}

//calcula o modulo de um vetor |vetor|
float modVetor(point3d vet){
 // return sqrt(pow(vet.x, 2) + pow(vet.y, 2) + pow(vet.z, 2));
    return sqrt((vet.x * vet.x) + (vet.y * vet.y) + (vet.z * vet.z));
}

//encontra o vetor Zv
point3d * Zv(point3d N){
  point3d * vet;
  vet = malloc(sizeof(point3d));
  float modulo;
 // modulo = modVetor(N);
  modulo  = sqrt((N.x * N.x) + (N.y * N.y) + (N.z * N.z));
  if(modulo == 0) modulo = 1;
  vet->x = N.x/modulo;
  vet->y = N.y/modulo;
  vet->z = N.z/modulo;
  return vet;
}

//encontra o vetor Xv
point3d * Xv(point3d V, point3d N){
  point3d * vet;
  float modulo;
  vet = malloc(sizeof(point3d));

  *vet = prodVetorial(V, N);
  modulo = modVetor(*vet);
  if(modulo == 0) modulo = 1;
  vet->x = vet->x/modulo;
  vet->y = vet->y/modulo;
  vet->z = vet->z/modulo;      
 
  return vet;
}

//encontra o vetor Yv
point3d * Yv(point3d Xv, point3d Zv){
  point3d * vet;
  float modulo;

  vet = malloc(sizeof(point3d));

  *vet = prodVetorial(Xv, Zv);
  return vet;
}
