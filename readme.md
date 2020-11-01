# DimArray

A simple library abstracting 1D arrays to work like multiple dimension arrays

## Installation

Either download a prebuilt binary from the release section.
Otherwise clone the repository and use `msbuild /p:TargetFrameworks=net472\` to compile against Mono 4.7.2 or `dotnet build /p:TargetFrameworks=netcoreapp3.1\` to target Net Core 3.1.

Drop the `DimArray.dll` into the project directory and add this to the `.csproj` in the right `ItemGroup`.
```xml
<Reference Include="DimArray">
    <HintPath>DimArray.dll</HintPath>
</Reference>
```

## Usage

```csharp
class Program
{
    static void Main(string[] args)
    {
        // This creates a "2D" array of the specifed size.
        var x = new DimArray.TwoDim<int>(5, 5);

        // Use it like you would use a normal C# 2D jagged array.
        for (int x = 0; x < testArray.X; x++)
        {
            for (int y = 0; y < testArray.Y; y++)
            {
                testArray[x, y] = Math.Pow(x + y, 2);
            }
        } 
    }

    // You can even print it!
    Console.WriteLine(x);
    Console.WriteLine(x.ToString1D());
}

```

## Other implementations
A CPP version can be found [here](https://github.com/AnzoDK/DimArray) made by AnzoDK.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://github.com/samhamnam/DimArray/blob/master/license)
