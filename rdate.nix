{ stdenv, lib, fetchFromGitHub, pkgs }:

stdenv.mkDerivation rec {
  pname = "rdate";
  version = "0.2.0";
  src = fetchFromGitHub {
    owner = "Wafelack";
    repo = "rdate";
    rev = "v${version}";
    sha256 = "0yxmrxg15gnfndcg4kyr5bmv4g0wqzz7zf1a6pjf90x069264npm";
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
