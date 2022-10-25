while (true)
{
    Console.Write("Enter x: ");
    double x = double.Parse(Console.ReadLine() ?? string.Empty);
    if (x == 0)
    {
        Console.Write("x cannot equal 0\n");
        Environment.Exit(0);
    }

    string tea = x switch
    {
        < -10 => "x is less than -10",
        < -1 and > -10 => "x is between -10 and -1",
        < 0 and > -1 => "x is between -1 and 0",
        > 1 and < 10 => "x is between 1 and 10",
        > 10 => "x is greater than 10",
        _ => "x is not between -10 and 10"
    };
    Console.Write($"{tea}\n");

    Console.Write("Enter y: ");
    double y = double.Parse(Console.ReadLine() ?? string.Empty);

    Console.Write("Enter z: ");
    double z = double.Parse(Console.ReadLine() ?? string.Empty);

    if ((z + z * z + (z + y * y)) != 0) // (y = ±1 & z = -1; y = 0 & z = -2; y = 0 & z = 0)
    {
        double functionResult = Math.Round(x + (y * y * y / (z + z * z + (z + y * y))), 2);
        Console.Write($"Function result: {functionResult}\n");
        Console.Write(functionResult > 0 ? "Positive\n\n" : "Negative\n\n");
    }
    else
    {
        Console.WriteLine("At such values of y and z the denominator is equal to zero\n");
    }
    
    Console.Write("Enter radius: ");
    double radius = double.Parse(Console.ReadLine() ?? string.Empty);

    if (radius > 0)
    {
        double perimeterResult = Math.Round((2 * Math.PI * radius), 2);
        Console.Write($"Perimeter result: {perimeterResult}\n");
        double areaResult = Math.Round((Math.PI * radius * radius), 2);
        Console.Write($"Area result: {areaResult}\n\n");
    }
    else
    {
        Console.WriteLine("Radius cannot be zero or negative\n");
    }
}