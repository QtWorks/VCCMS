/* Copyright 2015 Ruan Luies */
#ifndef VIRTUAL_CREATOR_VIRTUALCONCIERGE_H_
#define VIRTUAL_CREATOR_VIRTUALCONCIERGE_H_

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include "Objects/nodebutton.h"
#include "RenderStates/virtualconciergerenderstate.h"

namespace Ui {
class VirtualConcierge;
}

class VirtualConcierge : public QWidget {
    Q_OBJECT

 public:
    explicit VirtualConcierge(QWidget *parent = 0);
    ~VirtualConcierge();

 private:
    Ui::VirtualConcierge *ui;
    void create_interface();
    void load_interface(QString path_nodes, QString path_directories);
    int get_index_from_index(QVector<NodeButton* > node_list, int index);
    QVector<NodeButton *> buttons_, directories_, catagory_, temp;
    QVector<QString> directory_list_, node_list_;
    void load_config(QString file_name);
    bool show_email,
    show_access,
    enable_feet,
    enable_vehicle,
    enable_wheelchair,
    enable_bicycle,
    display_feet,
    display_vehicle,
    display_wheelchair,
    display_bicycle;

 private slots:
    void get_button_value(int index, bool significant);
    void on_pushButton_send_mail_clicked();
    void show_new_interface(int selected_node);
    void on_button_wheelchair_clicked();
    void on_button_feet_clicked();
    void on_button_bicycle_clicked();
    void on_button_other_vehicle_clicked();

signals:
    void send_access(bool wheelchair, bool feet, bool bicycle, bool vehicle);
    void find_path(int start, int goal);
    void disable_antialiasing(bool value);
};

#endif  // VIRTUAL_CREATOR_VIRTUALCONCIERGE_H_
