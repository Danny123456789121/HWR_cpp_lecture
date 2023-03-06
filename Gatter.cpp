#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>

// Die Gatter-Klasse
class Gatter {
public:
    virtual ~Gatter() {}
    virtual bool berechne(bool eingabe1, bool eingabe2) = 0;
    virtual std::string getName() const = 0;
    virtual std::string getInfo() const = 0;
};

// Die Und-Klasse, die von Gatter erbt
class Und : public Gatter {
public:
    bool berechne(bool eingabe1, bool eingabe2) override {
        return eingabe1 && eingabe2;
    }
    std::string getName() const override {
        return "Und-Gatter";
    }
    std::string getInfo() const override {
        return "Das Und-Gatter gibt 'wahr' zurück, wenn beide Eingaben 'wahr' sind.";
    }
};

// Die Oder-Klasse, die von Gatter erbt
class Oder : public Gatter {
public:
    bool berechne(bool eingabe1, bool eingabe2) override {
        return eingabe1 || eingabe2;
    }
    std::string getName() const override {
        return "Oder-Gatter";
    }
    std::string getInfo() const override {
        return "Das Oder-Gatter gibt 'wahr' zurück, wenn mindestens eine der Eingaben 'wahr' ist.";
    }
};

// Die Nicht-Klasse, die von Gatter erbt
class Nicht : public Gatter {
public:
    bool berechne(bool eingabe1, bool eingabe2) override {
        return !eingabe1;
    }
    std::string getName() const override {
        return "Nicht-Gatter";
    }
    std::string getInfo() const override {
        return "Das Nicht-Gatter gibt 'wahr' zurück, wenn die Eingabe 'falsch' ist.";
    }
};

// Die TestBot-Klasse
class TestBot {
public:
    TestBot() {
        // Füge einige Gatter hinzu
        gatterListe.push_back(std::make_unique<Und>());
        gatterListe.push_back(std::make_unique<Oder>());
        gatterListe.push_back(std::make_unique<Nicht>());
    }
    void start() {
        while (true) {
            // Zeige die verfügbaren Gatter
            std::cout << "Verfügbare Gatter:\n";
            for (int i = 0; i < gatterListe.size(); i++) {
                std::cout << i + 1 << ": " << gatterListe[i]->getName() << "\n";
            }
            std::cout << "q: Beenden\n";
            // Lese die Auswahl des Benutzers
            std::string auswahlStr;
            std::getline(std::cin, auswahlStr);
            if (auswahlStr == "q") {
                break;
            }
            // Konvertiere die Auswahl in eine Zahl
            std::istringstream iss(auswahlStr);
            int auswahl;
            if (!(iss >> auswahl) || auswahl < 1 || auswahl > gatterList
        // Wähle das ausgewählte Gatter aus
        std::unique_ptr<Gatter>& gatter = gatterListe[auswahl - 1];
        std::cout << "Sie haben das " << gatter->getName() << " ausgewählt.\n";
        // Lese die Eingaben des Benutzers
        std::string eingabeStr;
        std::cout << "Bitte geben Sie die Eingaben ein (mit Leerzeichen getrennt): ";
        std::getline(std::cin, eingabeStr);
        std::istringstream eingabeIss(eingabeStr);
        bool eingabe1, eingabe2;
        eingabeIss >> eingabe1 >> eingabe2;
        // Berechne das Ergebnis
        bool ergebnis = gatter->berechne(eingabe1, eingabe2);
        std::cout << "Das Ergebnis ist: " << ergebnis << "\n";
        // Zeige die Informationen zum ausgewählten Gatter
        std::cout << gatter->getInfo() << "\n";
    }
}
private:
std::vector<std::unique_ptr<Gatter>> gatterListe;
};

int main() {
TestBot testBot;
testBot.start();
return 0;
}
