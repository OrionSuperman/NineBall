
#include "StdAfx.h"
#include "BilliardBall.h"

using namespace NineBall;


Image^ BilliardBall::BallImage::get()
{
	return n_image;
}

void BilliardBall::BallImage::set(Image^ img)
{
	n_image = img;
}

bool BilliardBall::Moving::get()
{
	return n_moving;
}

void BilliardBall::Moving::set(bool isMoving)
{
	n_moving = isMoving;
}

bool BilliardBall::AddY::get()
{
	return n_addY;
}

void BilliardBall::AddY::set(bool addtoY)
{
	n_addY = addtoY;
}

double BilliardBall::SpeedX::get()
{
	return n_speedX;
}

void BilliardBall::SpeedX::set(double spX)
{
	n_speedX = spX;
}

double BilliardBall::PosX::get()
{
	return n_posX;
}

void BilliardBall::PosX::set(double pos_X)
{
	n_posX = pos_X;
}

double BilliardBall::FirstPos_X::get()
{
	return n_firstPosX;
}

void BilliardBall::FirstPos_X::set(double first_X)
{
	n_firstPosX = first_X;
}

double BilliardBall::FirstPos_Y::get()
{
	return n_firstPosY;
}

void BilliardBall::FirstPos_Y::set(double first_Y)
{
	n_firstPosY = first_Y;
}

double BilliardBall::MoveVal::get()
{
	return n_moveVal;
}

void BilliardBall::MoveVal::set(double move_Val)
{
	n_moveVal = move_Val;
}

double BilliardBall::SpeedY::get()
{
	return n_speedY;
}

void BilliardBall::SpeedY::set(double spY)
{
	n_speedY = spY;
}

double BilliardBall::PosY::get()
{
	return n_posY;
}

void BilliardBall::PosY::set(double posY)
{
	n_posY = posY;
}

double BilliardBall::Distance::get()
{
	return n_distance;
}

void BilliardBall::Distance::set(double dist)
{
	n_distance = dist;
}

double BilliardBall::Slope::get()
{
	return n_slope;
}

void BilliardBall::Slope::set(double slopeVal)
{
	n_slope = slopeVal;
}

float BilliardBall::Angle::get()
{
	return n_angle;
}

void BilliardBall::Angle::set(float angleVal)
{
	n_angle = angleVal;
}

double BilliardBall::Y_intercept::get()
{
	return n_y_intercept;
}

void BilliardBall::Y_intercept::set(double b)
{
	n_y_intercept = b;
}

Point BilliardBall::Destination::get()
{
	return n_dest;
}

void BilliardBall::Destination::set(Point dest)
{
	n_dest = dest;
}

Point BilliardBall::StartPos::get()
{
	return n_startPos;
}

void BilliardBall::StartPos::set(Point dest)
{
	n_startPos = dest;
}

