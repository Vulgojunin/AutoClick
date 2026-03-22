🖱️ AutoClicker PRO
Na real, começou como algo bobo: “to de ferias vou aprender a programar”. Só que fui colocando a mão no código e… a coisa cresceu.
No início era só um botão “Start” e “Stop”, uma janela feia e os cliques acontecendo sem parar. Mas quanto mais eu mexia, mais percebia a bagunça que tava fazendo. Variáveis jogadas de um lado pro outro, lógica da interface misturada com a da aplicação, o CMake me odiando, ponteiro me traindo… o clássico C++ sofrido.
Aí eu parei e pensei: “ou eu organizo isso direito agora, ou vou ter pesadelo com use-after-free pelo resto da vida.”
Foi quando resolvi levar o projeto a sério, como se fosse um software de verdade. Adotei Clean Architecture, e dividi tudo direitinho:
Core → a parte inteligente, onde o motor decide quando e como clicar
Application → os “casos de uso”, tipo “iniciar clique”, “parar tudo”
Controller → faz a ponte com a interface sem sujar as coisas
UI (Qt) → a carinha bonitinha que a gente vê na tela
Pelo caminho, usei alguns padrões que eu queria praticar:
Strategy → pra trocar facilmente entre clique fixo, clique com jitter, e futuramente burst, humanizado etc.
Observer → pra interface se atualizar sem ficar amarrada no motor (com unsubscribe pra não vazar memória)
Registry → pra criar os objetos sem sair dando new em qualquer lugar

Os maiores perrengues que enfrentei:
Thread morrendo e deixando ponteiro pendurado (use-after-free clássico)
Qt e threads se estranhando feio (sincronização sofrida)
CMake decidindo do nada que não ia compilar mais
VS Code mostrando erro em #include que compilava perfeitamente
Tentar usar o Qt Designer e depois integrar no código sem quebrar tudo
Mas cada surra que levei me ensinou alguma coisa. Hoje o projeto tá bem mais organizado e firme.

O que já funciona hoje:
Janela bonitinha com Qt
Start / Stop funcionando direitinho
Clique fixo + clique com jitter (pra parecer menos robô)
Sistema de notificação seguro entre a engine e a interface
Build com CMake rodando liso (finalmente!)

Próximos passos:
Hotkeys globais (tipo F6 pra ligar/desligar de qualquer lugar)
Mais estilos de clique: humanizado de verdade, burst, intervalos aleatórios inteligentes
Salvar e carregar configurações
Deixar o multithreading mais tranquilo e seguro
Dar um trato na interface (ícones, animações, dark mode decente)
Gerar .exe bonitinho
No fundo, mais do que ter um autoclicker foda, o projeto virou um laboratório pessoal pra estudar:
Arquitetura de software na prática
Design patterns que realmente fazem sentido
C++ moderno sem virar um Frankenstein
Qt sem sofrer tanto
Como organizar um projeto de verdade (e não só um main.cpp com 800 linhas)
Fiz com carinho usando C++17 + Qt 6 + CMake + MinGW.
Quem quiser dar uma olhada no código ou modificar fica a vontade!

Paulo Bento

AutoClicker PRO

Honestly, it started as something silly: “I’m on vacation, I’ll learn to code.” But once I got my hands on the code… things escalated.
At first, it was just a “Start” and “Stop” button, an ugly window, and clicks firing endlessly. But the more I tinkered, the more I realized the mess I was making. Variables thrown all over, UI logic tangled with application logic, CMake hating me, pointers betraying me… the classic C++ struggle.

Then I stopped and thought: “Either I organize this properly now, or I’ll have nightmares about use-after-free for the rest of my life.”

That’s when I decided to take the project seriously, like real software. I adopted Clean Architecture and split everything neatly:

Core → the brain, where the engine decides when and how to click

Application → the “use cases,” like “start clicking,” “stop everything”

Controller → bridges the UI without messing things up

UI (Qt) → the nice little face you see on screen

Along the way, I practiced some design patterns I wanted to try:

Strategy → to easily switch between fixed click, jitter click, and later burst, humanized, etc.

Observer → so the UI updates without being tied to the engine (with unsubscribe to avoid memory leaks)

Registry → to create objects without throwing new everywhere

Biggest struggles I faced:

Threads dying and leaving dangling pointers (classic use-after-free)

Qt and threads clashing badly (painful synchronization)

CMake randomly deciding it wouldn’t compile anymore

VS Code showing errors in #include that compiled just fine

Trying to use Qt Designer and then integrate it without breaking everything

But every beating taught me something. Today the project is way more organized and solid.

What works now:

Cute Qt window

Start / Stop working properly

Fixed click + jitter click (to look less robotic)

Safe notification system between engine and UI

Smooth CMake build (finally!)

Next steps:

Global hotkeys (like F6 to toggle anywhere)

More click styles: truly humanized, burst, smart random intervals

Save and load settings

Make multithreading calmer and safer

Polish the UI (icons, animations, proper dark mode)

Generate a neat .exe

In the end, more than building a badass autoclicker, the project became my personal lab to study:

Software architecture in practice

Design patterns that actually make sense

Modern C++ without turning into Frankenstein

Qt without suffering too much

How to organize a real project (not just a 800-line main.cpp)

I built it with care using C++17 + Qt 6 + CMake + MinGW.
Anyone who wants to check out or modify the code is welcome!