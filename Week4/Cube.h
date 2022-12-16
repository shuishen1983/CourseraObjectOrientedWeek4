#pragma once
/*
* enum HSLAPixel {
	blue = 0,
	orange = 1,
	purple = 2,
	yellow = 3,
};
*/

namespace uiuc {
	enum HSLAPixel {
		BLUE = 0,
		ORANGE = 1,
		PURPLE = 2,
		YELLOW = 3,
		WHITE = 4,
	};
	class Cube {
		public:
			Cube(double length, HSLAPixel color);
			
			double getLength() const;

			void setLength(double length);

			double getVolume() const;

			double getSurfaceArea() const;

			HSLAPixel getColor() const;

	private:
		double length_;
		HSLAPixel color_;
	};

}