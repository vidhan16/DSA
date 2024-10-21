//super class implementation
//interfaces and abstract correct usage
package geometry;
class Circle implements shape {
    double radius;

    public Circle(double r)
    {
        this.radius = r;
    }

    public double area()
    {
        return Math.PI * radius * radius;
    }

    public int numberOfSides()
    {
        return 0;
    }

    public String getName()
    {
        return "Circle";
    }
}

abstract class quad implements shape {
    public int numberOfSides()
    {
        return 4;
    }

    public String getName()
    {
        return "quad";
    }

    public abstract double area();
}

class Rectangle extends quad {
    double length;
    double breadth;

    public Rectangle(double l,double b)
    {
        this.length = l;
        this.breadth = b;
    }
    public String getName()
    {
        return "Rectangle";
    }

    public double area()
    {
        return length*breadth;
    }
}

class square extends Rectangle{
    double side;
    public square(double s)
    {
        super(s,s);
        side = s;
    }

    public String getName()
    {
        return "Square";
    }
}

class Triangle implements shape{
    double side1,side2,side3;
    public Triangle(double s1,double s2,double s3)
    {
        this.side1 = s1;
        this.side2 = s2;
        this.side3 = s3;
    }

    public double area()
    {
        double s = (side1+side2+side3)/2.0;
        return Math.sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }

    public String getName()
    {
        return "Triangle";
    }

    public int numberOfSides()
    {
        return 3;
    }
}
public class dimensions{
    public static void main(String[] args)
    {
        shape sq = new square(10);
        shape re = new Rectangle(5,10);
        System.out.println(sq.area());
        System.out.println(re.area());
    }
}
