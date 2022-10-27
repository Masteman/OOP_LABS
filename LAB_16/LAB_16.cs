using System;

namespace code
{
    internal delegate double Value(double x);

    internal delegate void MyEvent(ConsoleKeyInfo key);

    internal class MyEventClass
    {
        public event MyEvent KeyPress;

        public void Action()
        {
            if (KeyPress == null) return;
            var key = Console.ReadKey(true);
            KeyPress(key);
        }
    }

    internal static class Program
    {
        private static void Handler(ConsoleKeyInfo key)
        {
            var c = key.KeyChar;
            if (c == 'v' || c == 'V')
                Console.WriteLine($"VALENTINE, pressed '{c}'");
        }

        private static double TrapezoidMethod(Value t, double a, double b)
        {
            int i;
            double x;
            double sum = 0;
            const int n = 90;
            var dx = (b - a) / n;

            for (i = 0, x = a; i < n; i++)
            {
                sum += (t(x) + t(x + dx)) / 2 * dx;
                x += dx;
            }

            return sum;
        }

        private static double Function1(double x)
        {
            return 1 / x;
        }

        private static double Function2(double x)
        {
            return Math.Sqrt(4 + x * x);
        }

        private static double Function3(double x)
        {
            return Math.Sin(x);
        }

        private static void Main()
        {
            const double a = 1000;
            const double b = 5;

            Console.WriteLine(TrapezoidMethod(Function1, a, b));
            Console.WriteLine(TrapezoidMethod(Function2, a, b));
            Console.WriteLine(TrapezoidMethod(Function3, a, b));
            Console.ReadLine();

            var myEventClass = new MyEventClass();
            myEventClass.KeyPress += Handler;
            myEventClass.Action();
            Console.ReadLine();
        }
    }
}