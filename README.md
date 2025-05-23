<table width="100%">
  <tr>
  <td width="25%" align="center">OBJ</td>
  <td width="25%" align="center">USD</td>
  <td width="25%" align="center">FBX</td>
  <td width="25%" align="center">PLY</td>
  </tr>
  <tr>
  <td width="25%"><img src="https://github.com/s3gf4u17/3dgeolab-MeshConverter/assets/86662946/665948c3-00a5-4be7-ba05-196ace597c3f"/></td>
  <td width="25%"><img src="https://github.com/s3gf4u17/3dgeolab-MeshConverter/assets/86662946/bd0f2a7b-479b-4a9a-aea6-3f0b72e746b4"/></td>
  <td width="25%"><img src="https://github.com/s3gf4u17/3dgeolab-MeshConverter/assets/86662946/7ad6d29c-b499-4a04-bcae-ce3a5beeb8c4"/></td>
  <td width="25%"><img src="https://github.com/s3gf4u17/3dgeolab-MeshConverter/assets/86662946/a45ce56c-bf8b-4a4c-b6f3-95e43af7cac1"/></td>
  </tr>
</table>

## Spis treści

- [Przygotowanie środowiska](#przygotowanie-środowiska)
- [Kompilacja narzędzi](#kompilacja-narzędzi)
- [Wykorzystanie narzędzi](#wykorzystanie-narzędzi)
- [Licencje](#licencje)
    - [Assimp](#assimp)

## Przygotowanie środowiska

Instalacja biblioteki assimp:

```bash
sudo apt-get install libassimp-dev
```

## Kompilacja narzędzi

Kompilacja każdego z narzędzi po kolei:

```bash
g++ -o obj2usd obj2usd.cpp -O3 -lassimp
g++ -o obj2ply obj2ply.cpp -O3 -lassimp
g++ -o obj2fbx obj2fbx.cpp -O3 -lassimp
```

## Wykorzystanie narzędzi

Na wstępie należy umożliwić uruchomienie programu (jeżeli został pobrany z github releases):

```bash
chmod a+wrx <program>
```

Każdy z programów można uruchomić z wykorzystaniem tego samego schematu wywołania:

```bash
<program> <plik wejsciowy> <plik wyjsciowy>
```

Przykład

```bash
./obj2ply data/nmt.obj data/nmt.ply
```

## Licencje

### Assimp

> [!CAUTION]
> Wykorzystane pakiety: `assimp/postprocess.h`, `assimp/scene.h`, `assimp/Exporter.hpp`, `assimp/Importer.hpp`.

```
Open Asset Import Library (assimp)

Copyright (c) 2006-2021, assimp team
All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



******************************************************************************

AN EXCEPTION applies to all files in the ./test/models-nonbsd folder.
These are 3d models for testing purposes, from various free sources
on the internet. They are - unless otherwise stated - copyright of
their respective creators, which may impose additional requirements
on the use of their work. For any of these models, see
<model-name>.source.txt for more legal information. Contact us if you
are a copyright holder and believe that we credited you inproperly or
if you don't want your files to appear in the repository.


******************************************************************************

Poly2Tri Copyright (c) 2009-2010, Poly2Tri Contributors
http://code.google.com/p/poly2tri/

All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of Poly2Tri nor the names of its contributors may be
  used to endorse or promote products derived from this software without specific
  prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```
