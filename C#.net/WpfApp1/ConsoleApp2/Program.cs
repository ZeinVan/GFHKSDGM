
using System.Security.Cryptography.X509Certificates;

internal class Program
{
    private static void Main(string[] args)
    {
        int[] MyArrayOne = new int[50];
        for (int i = 0; i < 50; i++)
        {
                MyArrayOne[i] = i;

        }
        foreach (int i in MyArrayOne.Where(x =>
            {
                if (x % 2 == 0)
                    return true;
                return false;
                
            }
        ))

            Console.WriteLine(i);
        //Number 2
        int[] MyArrayTwo = new int[50];
        for (int i = 50; i < 100; i++)
        {
            MyArrayTwo[i] = i;

        }
        foreach (int i in MyArrayTwo.Where(x =>
        {
            if (x % 2 == 0)
                return true;
            return false;

        }
        ))

            Console.WriteLine(i);
        //Number3

        string[] MyArrayThree = { "stack", "panel", "dock", "grid", "array" };
        var results = MyArrayThree.Where(a => a.Contains("a"));
        foreach (var da in results) { 
            Console.WriteLine(da);
        }
        Console.WriteLine("Press to continue");
        Console.ReadKey();
        //Number 4
        int[] MyArrayFour = new int[100];
        for (int i =0; i < 100; i++)
        {
            MyArrayFour[i] = i;

        }
        var result = MyArrayFour.Select(x => x + 100);
        foreach (int i in result) {
            Console.WriteLine(i);
        }
        Console.ReadKey();
    } 
}