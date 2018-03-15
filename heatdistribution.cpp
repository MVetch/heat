#include "heatdistribution.h"
#include "ui_heatdistribution.h"

HeatDistribution::HeatDistribution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HeatDistribution)
{
    ui->setupUi(this);
}

HeatDistribution::~HeatDistribution()
{
    delete ui;
}
