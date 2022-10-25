namespace MyNamespace
{
    public class ComplexNumber
    {
        private double Real { get; init; }
        private double Imaginary { get; init; }

        public ComplexNumber() : this(0, 0)
        {
        }

        public ComplexNumber(double real, double imaginary)
        {
            Real = real;
            Imaginary = imaginary;
        }

        public override string ToString()
        {
            return Imaginary >= 0 ? $"{Real}+{Imaginary}i" : $"{Real}{Imaginary}i";
        }

        public static ComplexNumber operator +(ComplexNumber one, ComplexNumber two)
        {
            return new ComplexNumber(one.Real + two.Real, one.Imaginary + two.Imaginary);
        }

        public static ComplexNumber operator +(ComplexNumber one, double two)
        {
            return new ComplexNumber(one.Real + two, one.Imaginary);
        }

        public bool Equals(ComplexNumber other)
        {
            return Real.Equals(other.Real) && Imaginary.Equals(other.Imaginary);
        }
    }

    public static class Start
    {
        private static void Main()
        {
            var a = new ComplexNumber(1, -2);
            var b = new ComplexNumber(3, 4);

            Console.WriteLine($"{a}");
            Console.WriteLine($"{b}\n");

            Console.Write("c = a + b\n");
            var c = a + b;
            Console.WriteLine($"{c}\n");

            Console.Write("c = a + 10\n");
            c = a + 10;
            Console.WriteLine($"{c}\n");

            Console.WriteLine($"Is a = b ?\n{a.Equals(b)}");
            Console.WriteLine($"Is a = a ?\n{a.Equals(a)}");
        }
    }
}