
# **`Hangman`**
Hangman е конзолна версия на на играта на Бесеница.
Всеки играч може да си създаде профил и да се катери нагоре в класацията като познава думи от предварително създадена „банка“ с думи.

## 1. **`Как се играе`**
Играчът въвежда буква в конзолата,
 
//
//
//

ако на съответния индекс се съдържа търсената буква всяка нейна истанция се заменя в криптираната дума съдържаща "_".

## 2. **`Архитектура`**
Архитектурата на проекта е разделена на 4 класа като 3 от съдържат единствено статични функции предназначени да бъдат ползвани в класът repl, но отделени в отделни класове за по-добра четимост и удобство.

## **class repl**

    class repl {
    public:
	    void run();
    private:
	    unsigned int word_count = getword_count();
	    bool letters[26] = {false};

	    void mark_containing_letters(const string& str);
	    void cript_swap_letter(char l, string& cript, const string& word);

	    void safeTo_file(const string&, const string& crtipted, const string& word, unsigned int v);
	    void open_saved_game(const string& name);

	    const string cript(const string& word);
	    void addword(string& str);
	    void analyse_command(string &command);
	    void game(const string& name, unsigned v = 0, bool saved = true, string cripted = "", string word = "");
	    void login_command(string& name, string& str);
	    bool is_it_in(char x);
    };

Класът repl e мястото където се създава самата игра. Програмата ще съдържа метода:
    
    void repl::run()
което ще е единственото нещо което ще ползваме в main функцията.
тя ще ни препраща към:

    void repl::analyse_command(string &str)
Тук ще можем да анализираме командите:
1. `$ register` - регистрация на потребител с потребителско име, имейл и парола.
 Например: `$ register joro99 joro99@gmail.com 123456` или пример ако съществува вече такъв потребител `$ register joro99 joro99@gmail.com 123456`
2. `$ login` - влизане във вече създадения акаунт с потреителско име и парола. Например: `$ login joro99 123456` или при грешно потребителско име / парола: `$ login joro99 pa$$w0rD`
3. `$ forgotpass` - променяне на забравената вече парола чрез въвеждане на имейла свързан с профилът (функцията проверява дали въведения имейл съвпада със регистрирания). Например: `$ register joro99 joro99@gmail.com`
 
 които биват подавани от потребителя преди той да влезе в своя профил. Данните на всички регистрирани потребители се съхраняват във отделни файлове.

    void repl::login_command(string &name, string &str)

1. `addword` - добавяме дума в банката. Пример: `$ addword alcohol`
2. `exit` - излизаме от програмата.
3. `printword` - принтираме всички думи от банката.
4. `ranklist` - принтираме всички регистрирани потребители и техния резултат.
5. `playSaved` - въвеждаме име на файла на съществуващата игра.
6. `playNew` - стартиране на ново разиграване като биваме препратени към функцията void repl::game(...).

в случай на грешка се изважда "Ïnvalid command!"

    void repl::game(const string& name, unsigned v)

При стартиране на ново разиграване се изтегля на случаен принцип дума от „банката“ с думи. В началото на разиграването се разкрива първата буква от думата и всяко нейно срещане. По време на разиграването се визуализират използваните букви до момента и конзолно се визуализира фигурка, показваща бесеното човече.

Функцията запаметява играта при въвеждане на `#`:

    void safeTo_file(const string&, const string& crtipted, const string& word, unsigned int v);

използвайки ios::binary файлове, а пък дадената функция ни връща 

    void repl::open_saved_game(const string& name)

отваря вече запаметената игра след въвеждане на името на .txt файла.

## **class regest_login_system**

    class regest_login_system {
    public:
	    static void input_UserInfo(string& name, string& password, string& emails);
	    static bool forgot_pass(string user_name, string email);
	    static bool is_it_registered(const UserInfo& user);
	    static void regest(const UserInfo& user);
	    static bool login(const UserInfo& user);
	    static void change_password(const UserInfo& user);
    };

Работата на класа е да се грижи за създаването (`regest`) и влизането (`login`) на потребителя. Допълните му функционалности позволяват смяната на паролата (`forgot_pass`) и смяната на паролата `change_password`.

## **class Ranklist**

    class Ranklist {
    public:
	    static void ranklist_print();
	    static void ranklist(const string& name);
	    static void add_to_ranklist(const UserInfo& user);
    };

Класът `Ranklist` ни позволява да извеждаме общата класация на всички потребители `ranklist_print` да добавяме точка при спечелена игра `ranklist` или да добавяме самия потребител още при самата му регистрация `add_to_ranklist`.

## **class randomWord**

    class randomWord {
    public:
	    static unsigned int random_num(unsigned int word_count);
    	static const string random_word(unsigned int word_count);
    };

Създаваме произволно число `random_num` което връщаме във функцията `random_word` която сама по себе си връща произволна дума от банката с думи.

## **class Print**

    class Print {
    public:
	    static void print_cript(const string& cript);
	    static void print_guessed_letters(const bool* guessed_letters);
	    static void print_word_list(const unsigned int word_count);
    };

Колекция от всички `print` type функции

## **Helper_funk.h**

    void printHangman(unsigned short int x); // принтиране на всеки state на бесещото човече
    void to_up(char& x); // ако буквата е малка я прави главна
    void Press_anyKey_to_continue(const string& str);
    void UP_letter(char& g);
    bool is_it_won(const string& str);
    void reveal_Letter_by_index(string& str, string& word, unsigned int q); // показва всички истанции на дадената дума чрез въвеждането на индекс q
    const unsigned int getword_count();

