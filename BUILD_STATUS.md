# Build status

Este repositório possui um workflow do GitHub Actions para compilar o demo em um runner macOS hospedado pelo GitHub.

- **Workflow:** `.github/workflows/build-macos.yml`
- **Runner:** `macos-14`
- **Build command:** `make -C demo package FINALPACKAGE=1 THEOS="$THEOS" TARGET=iphone:clang:latest:16.0 V=1`
- **Saída esperada:** pacote `.deb` em `demo/packages/`, disponibilizado como artefato `api-fluck-demo-deb`

O build local neste sandbox não pôde ser concluído porque Theos e um iOS SDK não estão instalados. A tentativa local parou em:

```text
Makefile:18: *** Install Theos and set THEOS.  Stop.
```

A biblioteca `lib/libKeyAuth.a` já incluída no projeto é um binário Mach-O universal para `arm64` e `arm64e`; ela não é recompilada pelo demo.
