#include "Punto3D.h"

#pragma region Constructors
//Copy constructor
Punto3D::Punto3D(const Punto3D %copy)
{
	Distance = copy.Distance;
	Obstacle = copy.Obstacle;
	Intensity = copy.Intensity;
	Azimuth = copy.Azimuth;
	Angle = copy.Angle;
	x = copy.x;
	y = copy.y;
	z = copy.z;
}

/// <summary>
/// Initializes a new instance of the <see cref="Punto3D"/> class.
/// </summary>
/// <param name="d">The distance.</param>
/// <param name="i">The intensity.</param>
/// <param name="r">The horizontal angle.</param>
/// <param name="a">The vertical angle.</param>
Punto3D::Punto3D(double d, double i, double r, double a) {

	Distance = d;
	Intensity = i;
	Azimuth = r;
	Angle = a;
}
Punto3D::Punto3D(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
}
/// <summary>
/// Initializes a new instance of the <see cref="Punto3D"/> class.
/// </summary>
Punto3D::Punto3D() {
	Distance = -1;
	Intensity = -1;
	Azimuth = -1;
	Angle = -1;
	x = 0;
	y = 0;
	z = 0;
}

#pragma endregion

#pragma region Setters Implementations

/// <summary>
/// Sets the obstacle which contains the point.
/// </summary>
/// <param name="Obs">The number of the obstacle which contains the point.</param>
void Punto3D::setObstacle(int Obs)
{
	Obstacle = Obs;
}
/// <summary>
/// Sets the coordinates x.
/// </summary>
/// <param name="cx">The x coordinate.</param>
void Punto3D::setCoordinatesX(double cx) {
	x = cx;
}
/// <summary>
/// Sets the coordinates y.
/// </summary>
/// <param name="cy">The y coordinate.</param>
void Punto3D::setCoordinatesY(double cy) {
	y = cy;
}
/// <summary>
/// Sets the coordinates z.
/// </summary>
/// <param name="cz">The z coordinate.</param>
void Punto3D::setCoordinatesZ(double cz) {
	z = cz;
}
/// <summary>
/// Sets the distance.
/// </summary>
/// <param name="d">The distance.</param>
void Punto3D::setDistance(double d) {
	Distance = d;
}
/// <summary>
/// Sets the intensity.
/// </summary>
/// <param name="i">The intensity.</param>
void Punto3D::setIntensity(double i) {
	Intensity = i;
}
/// <summary>
/// Sets the azimuth.
/// </summary>
/// <param name="r">The horizontal angle.</param>
void Punto3D::setAzimuth(double r) {
	Azimuth = r;
}
/// <summary>
/// Sets the distance with bytes(Little endian ).
/// </summary>
/// <param name="i">First byte.</param>
/// <param name="j">Second byte.</param>
void Punto3D::setDistance(Byte i, Byte j)
{
	Distance = i + (j << 8);
	Distance /= 500; //Distance * 2 and convert from mm to m (/1000)
}
/// <summary>
/// Sets the intensity with bytes(Little endian ).
/// </summary>
/// <param name="i">The Byte.</param>
void Punto3D::setIntensity(Byte i)
{
	Intensity = i;
}
/// <summary>
/// Sets the azimuth with bytes(Little endian ).
/// <param name="i">First byte.</param>
/// <param name="j">Second byte.</param>
void Punto3D::setAzimuth(Byte i, Byte j)
{
	Azimuth = i + (j << 8);
	Azimuth /= 100;
}
/// <summary>
/// Sets the vertical angle.
/// </summary>
/// <param name="channel">The channel.</param>
void Punto3D::setAngle(int channel)
{
	switch (channel)
	{
	case 0: Angle = -15; break;
	case 1: Angle = 1; break;
	case 2: Angle = -13; break;
	case 3: Angle = 3; break;
	case 4: Angle = -11; break;
	case 5: Angle = 5; break;
	case 6: Angle = -9; break;
	case 7: Angle = 7; break;
	case 8: Angle = -7; break;
	case 9: Angle = 9; break;
	case 10: Angle = -5; break;
	case 11: Angle = 11; break;
	case 12: Angle = -3; break;
	case 13: Angle = 13; break;
	case 14: Angle = -1; break;
	case 15: Angle = 15; break;
	}
}

#pragma endregion

#pragma region Getters Implementation

/// <summary>
/// Gets the obstacle who contains the point.
/// </summary>
/// <returns></returns>
int Punto3D::getObstacle()
{
	return Obstacle;
}
/// <summary>
/// Gets the coordinates x.
/// </summary>
/// <returns></returns>
double Punto3D::getCoordinatesX() {
	return x;
}
/// <summary>
/// Gets the coordinates y.
/// </summary>
/// <returns></returns>
double Punto3D::getCoordinatesY() {
	return y;
}
/// <summary>
/// Gets the coordinates z.
/// </summary>
/// <returns></returns>
double Punto3D::getCoordinatesZ() {
	return z;
}
/// <summary>
/// Gets the distance.
/// </summary>
/// <returns></returns>
double Punto3D::getDistance() {
	return Distance;
}
/// <summary>
/// Gets the intensity.
/// </summary>
/// <returns></returns>
double Punto3D::getIntensity() {
	return Intensity;
}
/// <summary>
/// Gets the azimuth.
/// </summary>
/// <returns></returns>
double Punto3D::getAzimuth() {
	return Azimuth;
}
/// <summary>
/// Gets the angle.
/// </summary>
/// <returns></returns>
double Punto3D::getAngle()
{
	return Angle;
}
/// <summary>
/// Gets the module of the point.
/// </summary>
/// <returns></returns>
double Punto3D::getModule()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

#pragma endregion

#pragma region Others Functions

void Punto3D::visualize()
{
	Console::WriteLine("X: {0}\t Y: {1}\t Z: {2}",x,y,z);
}

/// <summary>
/// Calculates the coordinates.
/// </summary>
void Punto3D::CalculateCoordinates(double xx, double yy, double zz)
{
	x = (Distance*cos(Angle)*sin(Azimuth)) +xx;
	y = (Distance*cos(Angle)*cos(Azimuth)) + yy;
	z = (Distance*sin(Angle)) + zz;
}
/// <summary>
/// Distances between points.
/// </summary>
/// <param name="p">The p.</param>
/// <returns></returns>
double Punto3D::distanceToPoint(Punto3D^ p)
{
	return (p - this)->getModule();
}
String ^ Punto3D::verCoordenadas()
{
	return ""+ x +","+ y +","+ z;
}
#pragma endregion

#pragma region Operators

Punto3D^ Punto3D::operator+(Punto3D^ v)
{
	Punto3D^ result ;

	result->x = x + v->x;
	result->y = y + v->y;
	result->z = z + v->z;

	return result;
}
Punto3D^ Punto3D::operator*(double d)
{
	Punto3D^ result ;

	result->x = x * d;
	result->y = y * d;
	result->z = z * d;

	return result;
}
Punto3D^ Punto3D::operator-(Punto3D^ v)
{
	Punto3D^ result;

	result->x = x - v->x;
	result->y = y - v->y;
	result->z = z - v->z;

	return result;
}
Punto3D^ Punto3D::operator=(Punto3D^ v)
{
	Punto3D^ result;

	result->x = v->x;
	result->y = v->y;
	result->z = v->z;
	result->Angle = v->Angle;
	result->Azimuth = v->Azimuth;
	result->Distance = v->Distance;

	return result;
}

#pragma endregion