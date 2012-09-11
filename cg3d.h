// Jessica, Lucio, Viviane
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

#define EventMask (KeyPressMask | ExposureMask)
#define PI 3.1415926535

// coordenadas do universo 3D
float XWMax, XWMin, YWMax, YWMin, ZWMax, ZWMin;

// janela de visualizacao 2D
struct Window {
	float xmin, xmax, ymin, ymax;
};
typedef struct Window window;

// buffer de saida 2D
struct Buffer {
  	int MaxX, MaxY;
  	int * buffer;
};
typedef struct Buffer bufferdevice;

// viewport no SRD 2D
struct ViewPort {
  	int xmin, xmax, ymin, ymax;
};      
typedef struct Viewport viewport;

struct Point2D {
  	float x, y;
  	int	color;
};
typedef struct Point2D point2d;

struct Point3D{
	float x, y, z;
	int color;
};
typedef struct Point3D point3d;

struct Object2D {
  	int numbers_of_points;
  	point2d * points;
};
typedef struct Object2D object2d;  

struct Object3D {
  	int numbers_of_points;
  	point3d * points;
};  
typedef struct Object3D object3d;  

struct Color {
  	float red, green, blue;
};      
typedef struct Color ColorValues;    
  
struct Palette {
  	int numbers_of_colors;
  	ColorValues * colors;
};
typedef struct Palette palette;

struct HPoint2D {
  	float x, y, w;
};
typedef struct HPoint2D hpoint2d;

struct HPoint3D {
  	float x, y, z, w;
};
typedef struct HPoint3D hpoint3d;

struct HMatrix2D {
  float a11, a12, a13,
        a21, a22, a23,
        a31, a32, a33;
};
typedef struct HMatrix2D hmatrix2d;

struct HMatrix3D {
  float a11, a12, a13, a14,
        a21, a22, a23, a24,
        a31, a32, a33, a34,
		a41, a42, a43, a44;
};
typedef struct HMatrix3D hmatrix3d;

void SetWorld2d(float, float, float, float);
void SetWorld3d(float, float, float, float, float, float);
point2d * SetPoint2d(float, float, int);
point3d * SetPoint3d(float, float, float, int);
hpoint2d * SetHpoint2d(float, float, float);
hpoint3d * SetHpoint3d(float, float, float, float);
object2d * CreateObject2d(int);
object3d * CreateObject3d(int);
int SetObject2d(point2d *, object2d *);
int SetObject3d(point3d *, object3d *);
object2d * ChangeColor2d(object2d *, int);
object3d * ChangeColor3d(object3d *, int);
palette * CreatePalette(int);
int SetColor(float, float, float, palette *);
ColorValues * GetColor(int, palette *);
bufferdevice * CreateBuffer(int, int);
window * CreateWindow(float, float, float, float);
object2d * Circulo(point2d *, float);
object2d * Projection(object3d *, point3d *, point3d *);
point2d * Sru2Srn(point2d *, window *);
point2d * Srn2Srd(point2d *, bufferdevice *);
int InWin(point2d *, window *);
point2d * InterX(point2d *, point2d *, float);
point2d * InterY(point2d *, point2d *, float);
int DrawLine(point2d *, point2d *, window *, bufferdevice *, int);
int DrawObject(object2d *, window *, bufferdevice *);
int FillObject(bufferdevice *, int);
int Fill(object2d *, window *, bufferdevice *, int);
void CopyBuffer2Device(bufferdevice *, bufferdevice *);
void CopyView2Device(bufferdevice *, bufferdevice *, int, int);
object2d * Rotate2dz(object2d *, float);
object3d * Rotate3dz(object3d *, float);
object3d * Rotate3dx(object3d *, float);
object3d * Rotate3dy(object3d *, float);
object2d * Translate2d(object2d *, float, float);
object3d * Translate3dz(object3d *, float, float, float);
object3d * Translate3dx(object3d *, float, float, float);
object3d * Translate3dy(object3d *, float, float, float);
object2d * Scale2d(object2d *, float, float);
object3d * Scale3d(object3d *, float, float, float);
object2d * Mirror2dx(object2d *);
object3d * Mirror3dx(object3d *);
object2d * Mirror2dy(object2d *);
object3d * Mirror3dy(object3d *);
object3d * Mirror3dz(object3d *);
object2d * Shearing2dx(object2d *, float);
object2d * Shearing2dy(object2d *, float);
hpoint2d * Point2d2Hpoint2d(point2d *);
hpoint3d * Point3d2Hpoint3d(point3d *);
point2d * Hpoint2d2Point2d(hpoint2d *);
point3d * Hpoint3d2Point3d(hpoint3d *);
hpoint2d * LinearTransf2d(hmatrix2d *, hpoint2d *);
hpoint3d * LinearTransf3d(hmatrix3d *, hpoint3d *);
hmatrix2d * ComposeMatrix2d(hmatrix2d *, hmatrix2d *);
hmatrix3d * ComposeMatrix3d(hmatrix3d *, hmatrix3d *);
hmatrix2d * SetRotMatrix2d(float);
hmatrix3d * SetRotMatrix3d(float);
hmatrix2d * SetSclMatrix2d(float, float);
hmatrix3d * SetSclMatrix3d(float, float, float);
hmatrix2d * SetSftMatrix2d(float, float);
hmatrix3d * SetSftMatrix3d(float, float, float);
hmatrix2d * SetMirMatrix2dx();
hmatrix2d * SetMirMatrix2dy();
hmatrix3d * SetMirMatrix3dx();
hmatrix3d * SetMirMatrix3dy();
hmatrix3d * SetMirMatrix3dz();
hmatrix2d * SetMudMatrix2d(point2d *, point2d*, point2d *);
hmatrix3d * SetMudMatrix3d(point3d *, point3d *, point3d *, point3d *);
point3d * mudaBase(hmatrix3d * m, point3d * velho);
hmatrix2d * SetSheMatrix2dx(float);
hmatrix2d * SetSheMatrix2dy(float);
ColorValues * RGB2HSV(ColorValues *);
ColorValues * HSV2RGB(ColorValues *);
int DumpX(bufferdevice *, palette *);

point3d prodVetorial(point3d a, point3d b);
float modVetor(point3d vet);
point3d * Zv(point3d N);
point3d * Xv(point3d V, point3d N);
point3d * Yv(point3d Xv, point3d Zv);
