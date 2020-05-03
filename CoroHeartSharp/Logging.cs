using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CoroHeart
{
    public enum LoggingLevel
    {
        Info,
        Warning,
        Error
    }
   public static class Logging
    {
        [DllImport(Constants.DLLName, EntryPoint = "COROH_InitGameLogging" )]
        public extern static void InitGameLogging();

        [DllImport(Constants.DLLName, EntryPoint = "COROH_StopGameLogging")]
        public extern static void StopGameLogging();

        [DllImport(Constants.DLLName,EntryPoint = "COROH_InitConsole")]
        public extern static void InitConsole();
        [DllImport(Constants.DLLName, EntryPoint = "COROH_CloseConsole")]
        public extern static void CloseConsole();

        [DllImport(Constants.DLLName, EntryPoint = "COROH_Log")]
        public extern static void Log(LoggingLevel loggingLevel, string format, string[] args);
    }
}
