# day1

### example 01 - projekt sa raznim konfiguracijama (Debug, DebugU, Release, ReleaseU) i platformama (32, 64)

Isprobajte build i ispis na raznim varijantama.

### exercise 01 - korištenje statičke biblioteke (.lib) i dinamičke biblioteke (.dll, na dva načina)

Napravite projekt app (.exe) u folderu app koji poziva i ispisuje rezultat:
- funkcije `get_value` iz static_library.lib (lib/public.h)
- funkcije `get_value` iz dynamic_library.dll (potpis: `double get_value(int)`)
- funkcije `get_value` iz dynamic_library_with_implib.dll (dll2/public.h)

Uputstva:
- za dynamic_library.dll trebat će vam Windows API funkcije [LoadLibrary](https://docs.microsoft.com/en-us/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya), [GetProcAddress](https://docs.microsoft.com/en-us/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress), [FreeLibrary](https://docs.microsoft.com/en-us/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary).

### exercise 02 - Unit testovi za jednostavne funkcije.

Odkomentirajte poziva funkcija `f1` i `f2` i napravite da sva tri testa uspješno prođu u Test Exploreru.
