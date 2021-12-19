{ stdenv, lib, fetchFromGitHub, pkgs }:

stdenv.mkDerivation rec {
  pname = "rdate";
  version = "0.1.0";
  src = fetchFromGitHub {
    owner = "Wafelack";
    repo = "rdate";
    rev = "v${version}";
    sha256 = "1s8l17ck1myijq5wfvng3zznbn2bjb88g18rlvl02qsadqxg53x9";
  };

  installPhase = ''
    make
    mkdir -p $out/bin/
    install -m 711 -t $out/bin/ rdate
    mkdir -p $out/share/man/man1/
    cp rdate.1 $out/share/man/man1/rdate.1
  '';

  nativeBuildInputs = with pkgs; [ gcc gnumake ];

  meta = {
    homepage = "https://github.com/Wafelack/rdate";
    description = "Afficher la date et l'heure suivant le calendrier républicain.";
    platforms = lib.platforms.all;
    license = lib.licenses.gpl3Plus;
  };
}
