#ifndef POSITION_H
#define POSITION_H
class Position
{
	public:
		Position(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
		Position()
		{
			x = 0;
			y = 0;
		}
		~Position() {}
		
		void from(Position pos)
		{
			x = pos.getX();
			y = pos.getY();
		}
		
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		void setX(int _x)
		{
			x = _x;
		}
		void setY(int _y)
		{
			y = _y;
		}
		void setXY(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
	private:
		int x, y;
};
#endif
