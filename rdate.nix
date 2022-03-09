{ stdenv, lib, fetchFromGitHub, pkgs }:

stdenv.mkDerivation rec {
  pname = "rdate";
  version = "0.4.0";
  src = fetchFromGitHub {
    owner = "Wafelack";
    repo = "rdate";
    rev = "v${version}";
    sha256 = "0xlds1cjw4cg5vh8mwdr2qd7dslllc11lvvb02awjnmbwn6hbyh9";
  };

  CFLAGS = "-O3";

  buildPhase = ''
    make
  '';

  installPhase = ''
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
