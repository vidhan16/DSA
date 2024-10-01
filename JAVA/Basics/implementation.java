//In case of non static function it is must to create object of class to call the function without doing so the function can not be accessed within class;

// class implementation {
//     public int add(int a,int b)
//     {
//         return a+b;
//     }
//     public static void main(String[] args) {
//         implementation a = new implementation();
//         System.out.println(a.add(1,2));
//     }
// }


//In case of static functions

// class implementation {
//     public static int add(int a,int b)
//     {
//         return a+b;
//     }
//     public static void main(String[] args) {
//         System.out.println(add(1,2));
//     }
// }