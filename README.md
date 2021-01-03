# CoroHeart
Modding engine for compile heart games using the Orochi engine such as Death End Re;Quest and Megadimension Neptunia VIIR

## Compiling (For programmers)
1. Download Visual Studio 2019.
2. Open this repository in GitHub desktop to clone the repo.
3. Run [setup.bat](setup.bat) to start the initial compile process for [Detours](https://github.com/microsoft/Detours), which is a dependency for CoroHeart to function.
4. Open [CoroHeart.sln](CoroHeart.sln) in Visual Studio, and make sure the build setting is set to either Debug or Release x64.
5. Go to the properties for the "CoroHeart" and "D3D11Proxy" projects, and change the output directory to where the "resource/bin" subdirectory in the game's install directory is.
6. Build the solution.