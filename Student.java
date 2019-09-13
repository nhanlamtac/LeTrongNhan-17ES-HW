
public class Student {
        private String name;
        private long id;
        private double mathMark, englishMark, physicsMark, chemistryMark;
        public Student(String name, long id)
        {
                 this.name = name;
                 this.id = id;
        }
        public void setMathMark(double value)
        {
                 if(value>0 && value<=100)
                 {
                           mathMark = value;
                 }
                  }
                 public void setEnglishMark (double value)
                 {
                           if(value>0 && value<=100)
                           {
                                    englishMark = value;
                           }
                 }
                 public void setPhysicsMark (double value)
                 {
                           if(value>0 && value<=100)
                           {
                                    physicsMark = value;
                           }
                 }
                 public void setChemistryMark (double value)
                 {
                           if(value>0 && value<=100)
                 {
                           chemistryMark = value;
                 }
        }
        public double getAverage()
        {
                 double result=0;
                 //add your code here
                 result= (mathMark+englishMark+physicsMark+chemistryMark)/4;


                 return result;
        }
        public void displayDetails()
        {
        		System.out.println("Name: "+name);
        		System.out.println("Id= "+id);
                System.out.println("Average= " +getAverage());
}

        public static void main(String args[])
        {
                 Student std = new Student("Haim",123123);
                 std.setChemistryMark(98);
                 std.setEnglishMark(88);
                 std.setPhysicsMark(78);
                 std.setMathMark(100);
                 std.displayDetails();
}


}
