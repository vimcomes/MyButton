#include <QApplication>
#include "button.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ImageButton slideButton(nullptr);
    slideButton.setFixedSize(300,126);
    slideButton.move(1000,400);
    auto *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/buttonSound.mp3"));
    player->setVolume(75);
    QObject::connect(&slideButton, &QPushButton::clicked, &slideButton, &ImageButton::setButton);
    QObject::connect(&slideButton, &QPushButton::clicked, [&player](){player->play();});
    slideButton.show();
    return QApplication::exec();
}
