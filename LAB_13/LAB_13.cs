using System;
using System.Collections.Generic;

namespace code
{
    internal static class Program
    {
        private abstract class Flowers
        {
            public string Color;
            public double Price;

            protected Flowers(string color, double price)
            {
                this.Color = color;
                this.Price = price;
            }

            public override string ToString()
            {
                return $"{nameof(Color)}: {Color}, {nameof(Price)}: {Price}";
            }
        }

        private class Rose : Flowers
        {
            public Rose(string color, double price) : base(color, price)
            {
            }

            public override string ToString()
            {
                return $"Rose: {base.ToString()}";
            }

            public bool Equals(Flowers other)
            {
                return Color == other.Color && Price == other.Price;
            }
        }

        private class Tulip : Flowers
        {
            public Tulip(string color, double price) : base(color, price)
            {
            }

            public override string ToString()
            {
                return $"Tulip: {base.ToString()}";
            }

            public bool Equals(Flowers other)
            {
                return Color == other.Color && Price == other.Price;
            }
        }

        private class Violet : Flowers
        {
            public Violet(string color, double price) : base(color, price)
            {
            }

            public override string ToString()
            {
                return $"Violet: {base.ToString()}";
            }

            public bool Equals(Flowers other)
            {
                return Color == other.Color && Price == other.Price;
            }
        }


        private static void Main()
        {
            var bouquet = new List<Flowers>
            {
                new Rose("red", 540),
                new Tulip("blue", 201),
                new Violet("violet", 304)
            };

            double totalPrice = 0;

            foreach (var item in bouquet)
            {
                Console.WriteLine($"{item}");
                totalPrice += item.Price;
            }

            Console.WriteLine($"Total price: {totalPrice}");

            var p1 = new Rose("red", 540);
            var p2 = new Rose("red", 540);
            Console.WriteLine($"\nRose: {p1.Equals(p2)}");

            var c1 = new Tulip("red", 201);
            var c2 = new Tulip("blue", 402);
            Console.WriteLine($"Tulip: {c1.Equals(c2)}");
        }
    }
}