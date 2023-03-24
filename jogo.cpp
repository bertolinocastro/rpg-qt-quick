#include<iostream>
using namespace std;

/*
 * Personagens: mago, bruxa, cavaleiro, princesa, aldeao, monstro, dragao.
 */

class FormaDeVida {
	protected:
		string nome;
		int vida;  // Faixa de valores: 0 a 100.
		int forca; // Faixa de valores: 0 a 100.

	public:
		FormaDeVida() {
			vida = 100;
			forca = 100;
		}
		FormaDeVida(string n) {
			nome = n;
			vida = 100;
			forca = 100;
		}
		void setNome(string n) {
			nome = n;
		}
		string getNome() {
			return nome;
		}
		void setVida(int v) {
			if (v >= 0 && v <= 100) {
				vida = v;
			}
		}
		int getVida() {
			return vida;
		}
		void setForca(int f) {
			if (f >= 0 && f <= 100) {
				forca = f;
			}
		}
		int getForca() {
			return forca;
		}
};

class SerHumano : public FormaDeVida {
	public:
		SerHumano() : FormaDeVida() {
		}
		SerHumano(string n) : FormaDeVida(n) {
		}

		void fale(string s) {
			cout << getNome() << " disse: " << s << "\n";
		}

		virtual string responda(string s) {
			if (s == "Ola!") {
				return "Tudo bem?";
			} else if (s == "Tudo bem?") {
				return "Sim, e voce?";
			} else if (s == "Sim, e voce?") {
				return "Estou otimo!";
			} else if (s == "Ate logo!") {
				return "Ate!";
			} else if (s == "Tchau!") {
				return "Ate!";
			} else {
				return "Nao sei dizer.";
			}
		}

		template <class ClasseTemplate>
		void converse(ClasseTemplate pessoa, string s) {
			string respostaPessoa;
			string minhaResposta;
			minhaResposta = s;
			while (true) {
				this->fale(minhaResposta);
				respostaPessoa = pessoa.responda(minhaResposta);
				pessoa.fale(respostaPessoa);
				minhaResposta = this->responda(respostaPessoa);
				if (respostaPessoa == "Nao sei dizer." || minhaResposta == "Nao sei dizer.") {
					break;
				}
			}
		}
};

class Mago : public SerHumano {
	protected:
		int magia;

	public:
		Mago() : SerHumano() {
			magia = 100;
		}
		Mago(string n) : SerHumano(n) {
			magia = 100;
		}

		void setMagia(int m) {
			if (m >= 0 && m <= 100) {
				magia = m;
			}
		}
		int getMagia() {
			return magia;
		}
};

class Bruxa : public SerHumano {
	protected:
		int magia;

	public:
		Bruxa() : SerHumano() {
			magia = 100;
		}
		Bruxa(string n) : SerHumano(n) {
			magia = 100;
		}

		void setMagia(int m) {
			if (m >= 0 && m <= 100) {
				magia = m;
			}
		}
		int getMagia() {
			return magia;
		}
};

class Cavaleiro : public SerHumano {
	protected:
		int coragem;
		int armadura;

	public:
		Cavaleiro() : SerHumano() {
			coragem = 100;
			armadura = 100;
		}
		Cavaleiro(string n) : SerHumano(n) {
			coragem = 100;
			armadura = 100;
		}

		void setCoragem(int c) {
			if (c >= 0 && c <= 100) {
				coragem = c;
			}
		}
		int getCoragem() {
			return coragem;
		}
		void setArmadura(int a) {
			if (a >= 0 && a <= 100) {
				armadura = a;
			}
		}
		int getArmadura() {
			return armadura;
		}

		virtual string responda(string s) {
			if (s == "Ola!") {
				return "Como vai nobre pessoa?";
			} else if (s == "Tudo bem?") {
				return "Sim, e como esta Vossa senhoria?";
			} else if (s == "Sim, e voce?") {
				return "Estou passando muitissimo bem!";
			} else if (s == "Ate logo!") {
				return "Ate proxima!";
			} else if (s == "Tchau!") {
				return "Ate logo!";
			} else {
				return "Nao sei dizer.";
			}
		}
};

class Princesa : public SerHumano {
	protected:
		int inteligencia;
		int beleza;
		int dinheiro;

	public:
	    void init() {
		    inteligencia = 50;
		    beleza = 100;
		    dinheiro = 20;
	    }
		Princesa() : SerHumano() {
		    this->init();
		}
		Princesa(string n) : SerHumano(n) {
            this->init();
		}

		void setInteligencia(int i) {
			if (i >= 0 && i <= 100) {
				inteligencia = i;
			}
		}
		int getInteligencia() {
			return inteligencia;
		}
		void setBeleza(int b) {
			if (b >= 0 && b <= 100) {
				beleza = b;
			}
		}
		int getBeleza() {
			return beleza;
		}
		void setDinheiro(int d) {
			if (d >= 0 && d <= 100) {
				dinheiro = d;
			}
		}
		int getDinheiro() {
			return dinheiro;
		}

		string responda(string s) {
			if (s == "Ola!") {
				return "To de boa, e oce?";
			} else if (s == "To de boa, e oce?") {
				return "Estou ótima!";
			} else if (s == "Nao e de sua conta!") {
				return "Seu mal educado!";
			} else if (s == "Entao sarta fora!") {
				return "Vou chamar meu pai!";
			} else if (s == "Se manda!") {
				return "Você já era!";
			} else if (s == "Você já era!") {
				return "To nem ai!";
			} else {
				return "Nao sei dizer.";
			}
		}
};

class Aldeao : public SerHumano {
	protected:
		int lealdade;
		int honestidade;

	public:
	    void init() {
		    lealdade = 0;
		    honestidade = 0;
	    }
		Aldeao() : SerHumano() {
		    this->init();
		}
		Aldeao(string n) : SerHumano(n) {
		    this->init();
		}

		void setLealdade(int l) {
			if (l >= 0 && l <= 100) {
				lealdade = l;
			}
		}
		int getLealdade() {
			return lealdade;
		}
		void setHonestidade(int h) {
			if (h >= 0 && h <= 100) {
				honestidade = h;
			}
		}
		int getHonestidade() {
			return honestidade;
		}

		string responda(string s) {
			if (s == "Ola!") {
				return "To de boa, e oce?";
			} else if (s == "Tudo bem?") {
				return "Nao e de sua conta!";
			} else if (s == "Sim, e voce?") {
				return "Entao sarta fora!";
			} else if (s == "Estou ótima!") {
				return "Entao sarta fora!";
			} else if (s == "Vou chamar meu pai!") {
				return "To nem ai!";
			} else if (s == "Ate logo!") {
				return "Se manda!";
			} else if (s == "Tchau!") {
				return "To nem ai!";
			} else {
				return "Nao sei dizer.";
			}
		}
};

class Monstro : public FormaDeVida {
	protected:
		int simpatia;

	public:
	    void init() {
		    simpatia = 0;
	    }
		Monstro() : FormaDeVida() {
		    this->init();
		}
		Monstro(string n) : FormaDeVida(n) {
		    this->init();
		}

		void setSimpatia(int s) {
			if (s >= 0 && s <= 100) {
				simpatia = s;
			}
		}
		int getSimpatia() {
			return simpatia;
		}
};

class Dragao : public Monstro {
	protected:
		int fogo;

	public:
	    void init() {
		    fogo = 0;
	    }
		Dragao() : Monstro() {
		    this->init();
		}
		Dragao(string n) : Monstro(n) {
		    this->init();
		}

		void setFogo(int f) {
			if (f >= 0 && f <= 100) {
				fogo = f;
			}
		}
		int getFogo() {
			return fogo;
		}
};

Mago merlin("Merlin");
Bruxa magaPatalogica("Maga Patalogica");
Cavaleiro arthur("Arthur");
Aldeao tiago("Tiago");
Princesa leia("Leia");
Monstro lucas("Lucas");
Dragao tiamat("Tiamat");

int introducao() {
    char continuar;

    system("clear");

    cout << "A Princesa Malevola\n";

printf(R"EOF(

 [][][] /""\ [][][]
  |::| /____\ |::|
  |[]|_|::::|_|[]|
  |::::::__::::::|
  |:::::/||\:::::|
  |:#:::||||::#::|
 #@*###&*##&*&#*&##
##@@*####*@@@###*@*#

)EOF");

    cout << "Deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    cout << " Tudo ia bem no pacato reino de Ana Lucia\n";
    cout << " Ate que a princesa Leia completou 15 anos\n";
    cout << "Entao ela juntou-se a bruxa Maga Patalogica\n";
    cout << "  E exigiu de seus pais o rei e a rainha\n";
    cout << "que ordenassem aos aldeoes que entregassem\n";
    cout << "Seus filhos mais novos para suas sinistras\n";
    cout << "              Experiencias...\n\n";

    cout << "Deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    return 1;
}

int capitulo1() {
    char continuar;

    system("clear");

    cout << "    Capitulo 1\n";
    cout << "Tiago Procura Ajuda\n";

printf(R"EOF(

     """""""
     ^-O-O-^
---ooO--U--Ooo-----

)EOF");

    cout << "Deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    cout << "Tiago muito preocupado com o destino\n";
    cout << "  terrivel que acometeu o reino\n";
    cout << "    Procura o cavaleiro artur\n";

    cout << "Deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

printf(R"EOF(

 _/ _ _ \_
(o / | \ o)
 || o|o ||
 | \_|_/ |
 |  ___  |
 | (___) |
 |\_____/|
 | \___/ |
 \       /
  \__ __/
     U

)EOF");

    cout << "        Cavaleiro Artur\n";
    cout << "   O reino precisa de sua ajuda \n";
    cout << " A princesa Leia tem tornado as vidas\n";
    cout << "      dos aldeaos um pesadelo\n";
    cout << "     O senhor pode nos ajudar?\n";

    cout << "Voce acha que Artur deve ajudar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    cout << "            Nobre Tiago\n";
    cout << "  Nesta jornada precisaremos da ajuda \n";
    cout << "     do nobre Mago Merlin\n";
    cout << "    mas ele mora alem das montanhas\n";
    cout << "     e a viagem e muito perigosa\n";

    cout << "Voce deseja seguir alem das montanhas\n";
    cout << "   e procurar o Mago Merlin (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    return 1;
}

int capitulo2() {
    char continuar;

    system("clear");

    cout << "  Capitulo 2\n";
    cout << "  A Jornada\n";

printf(R"EOF(

        _    .  ,   .           .
    *  / \_ *  / \_      _  *        *   /\'__        *
      /    \  /    \,   ((        .    _/  /  \  *'.
 .   /\/\  /\/ :' __ \_  `          _^/  ^/    `--.
    /    \/  \  _/  \-'\      *    /.' ^_   \_   .'\  *
  /\  .-   `. \/     \ /==~=-=~=-=-;.  _/ \ -. `_/   \
 /  `-.__ ^   / .-'.--\ =-=~_=-=~=^/  _ `--./ .-'  `-
/jgs     `.  / /       `.~-^=-=~=^=.-'      '-._ `._

)EOF");

    cout << "Deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    cout << "Tiago e Artur chegam as montanhas do reino\n";
    cout << "  Artur adverte Tiago que um terrivel\n";
    cout << "     monstro guarda a entrada\n";
    cout << "       Tiago treme de medo\n";

    cout << "Voce acha que Tiago deve enfrentar o medo\n";
    cout << "e seguir (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

printf(R"EOF(

        .-"""".
       /       \
   __ /   .-.  .\
  /  `\  /   \/  \
  |  _ \/   .==.==.
  | (   \  /____\__\
   \ \      (_()(_()
    \ \            '---._
     \                   \_
  /\ |`       (__)________/
 /  \|     /\___/
|    \     \||VV
|     \     \|"""",
|      \     ______)
\       \  /`
jgs      \(

)EOF");

    cout << "Surge o monstro no pe da montanha\n";
    cout << "Voce acha que Tiago deve enfrentar\n";
    cout << "o monstro (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    tiago.setVida(tiago.getVida() - 10);

    cout << "              Tiago e ferido\n";
    cout << "     Tiago agora tem " << tiago.getVida() << " de vida\n";

    cout << "Voce acha que Tiago deve continuar com\n";
    cout << "artur (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    printf(R"EOF(

    _     _
   /.\   ( )
  /   \   \\
  \,-./    \
  ( oo)  /\{}
   \_=/ /  \ \
  //  \/ ,'   \
 ||    |'      \
 ||    |        \
 m|    |
  |____|
    `-`-

)EOF");

    cout << "Tiago e Artur encontram o Mago Merlin\n";
    arthur.converse<Mago>(merlin, "Ola!");
    arthur.fale("Precisamos de sua ajuda");
    arthur.fale("A princesa Leia tem aterrorizado o reino");
    arthur.fale("Voce pode nos ajudar?");

    cout << "Voce acha que Merlin deve ajuda (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    return 1;
}

int capitulo3() {
        char continuar;

    system("clear");

    cout << "   Capitulo 3\n";
    cout << "  O Confronto\n";

printf(R"EOF(

        w*W*W*W*w
         \"."."/
          //`\\
         (/a a\)
         (\_-_/)
        .-~'='~-.
       /`~`"Y"`~`\
      / /(_ * _)\ \
     / /  )   (  \ \
     \ \_/\\_//\_/ /
      \/_) '*' (_\/
        |       |
        |       |
        |       |
        |       |
        |       |
        w*W*W*W*w

)EOF");

    cout << "Deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

printf(R"EOF(

       \****__              ____
         |    *****\_      --/ *\-__
         /_          (_    ./ ,/----'
Art by     \__         (_./  /
 Ironwing     \__           \___----^__
               _/   _                  \
        |    _/  __/ )\"\ _____         *\
        |\__/   /    ^ ^       \____      )
         \___--"                    \_____ )
                                          "
)EOF");

    cout << "Tiago, Artur e Merlin retornam ao castelo\n";
    cout << "       Merlin invoca um dragao\n";

    cout << "Voce acha que o dragao deve atacar a princesa (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

printf(R"EOF(

                _ ___                /^^\ /^\  /^^\_
    _          _X X  \            ,,/ '` ~ `'~~ ', `\.
  _/o\_ _ _ _/~`.`...'~\        ./~~..,'`','',.,' '  ~:
 / `,'.~,~.~  .   , . , ~|,   ,/ .,' , ,. .. ,,.   `,  ~\_
( ' _' _ '_` _  '  .    , `\_/ .' ..' '  `  `   `..  `,   \_
 ~V~ V~ V~ V~ ~\ `   ' .  '    , ' .,.,''`.,.''`.,.``. ',   \_
  _/\ /\ /\ /\_/, . ' ,   `_/~\_ .' .,. ,, , _/~\_ `. `. '.,  \_
 < ~ ~ '~`'~'`, .,  .   `_: ::: \_ '      `_/ ::: \_ `.,' . ',  \_
  \ ' `_  '`_    _    ',/ _::_::_ \ _    _/ _::_::_ \   `.,'.,`., \-,-,-,_,_,
   `'~~ `'~~ `'~~ `'~~  \(_)(_)(_)/  `~~' \(_)(_)(_)/ ~'`\_.._,._,'_;_;_;_;_;

)EOF");

    tiamat.setVida(tiamat.getVida() - 100);

    cout << "              O dragao fica muito ferido\n";
    cout << "     O draga agora tem " << tiamat.getVida() << " de vida\n";

    cout << "Voce deseja continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    tiago.setVida(tiago.getVida() - 50);
    arthur.setVida(arthur.getVida() - 20);

    cout << "              Tiago e Artur sao feridos\n";
    cout << "     Tiago agora tem " << tiago.getVida() << " de vida\n";
    cout << "     Artur agora tem " << arthur.getVida() << " de vida\n";

    cout << "Voce acha que Tiago e Artur devem continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    printf(R"EOF(

                        ______
             ______,---'__,---'
         _,-'---_---__,---'
  /_    (,  ---____',
 /  ',,   `, ,-'
;/)   ,',,_/,'
| /\   ,.'//\
`-` \ ,,'    `.
     `',   ,-- `.
     '/ / |      `,         _
     //'',.\_    .\\      ,{==>-
  __//   __;_`-  \ `;.__,;'
((,--,) (((,------;  `--' jv

)EOF");

    cout << "O Mago Merlin invoca o terrive Grifo\n";

    system("clear");

    leia.setVida(leia.getVida() - 100);

    cout << "              Leia e gravimente ferida\n";
    cout << "     Leia agora tem " << leia.getVida() << " de vida\n";

    cout << "Voce acha que Tiago, Artur e Merlin devem continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    printf(R"EOF(

                                   .''.
       .''.      .        *''*    :_\/_:     .
      :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.
  .''.: /\ :   ./)\   ':'* /\ * :  '..'.  -=:o:=-
 :_\/_:'.:::.    ' *''*    * '.\'/.' _\(/_'.':'.'
 : /\ : :::::     *_\/_*     -= o =-  /)\    '  *
  '..'  ':::'     * /\ *     .'/.\'.   '
      *            *..*         :
jgs     *

)EOF");

    cout << "Nossos herois vencem!\n";

    cout << "Continuar (s/n)? ";
    cin >> continuar;

    if (continuar == 'n') {
        return 0;
    }

    system("clear");

    return 1;
}

int main(void) {
	if (!introducao()) {
	    system("clear");

	    cout << "Fim de jogo!";

	    return 0;
	} else {
	    if (!capitulo1()) {
    	    system("clear");

	        cout << "Fim de jogo!";

            return 0;
	    } else {
	        if (!capitulo2()) {
        	    system("clear");

    	        cout << "Fim de jogo!";

                return 0;
    	    } else {
    	        if (!capitulo3()) {
            	    system("clear");

        	        cout << "Fim de jogo!";

                    return 0;
        	    } else {
        	        system("clear");

        	        cout << "Parabens! Voce venceu!";

                    return 0;
        	    }
    	    }
	    }
	}

	return 0;
}