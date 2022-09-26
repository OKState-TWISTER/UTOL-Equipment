#ifndef CUSTOMQWTPLOT_H
#define CUSTOMQWTPLOT_H

class DialogQwtPlotDetails;
#include <qwt_plot.h>
class QLabel;
class QPoint;
class QResizeEvent;
class QWidget;

class CustomQwtPlot : public QwtPlot
{
	Q_OBJECT
public:
	explicit CustomQwtPlot(QWidget *parent = 0);
	QLabel *label_Statistic;
	void setAxisScaleEngineLog(int axisId, bool bIsLog);
	bool getAxisScaleEngineLog(int axisId);

signals:

public slots:

private slots:
	void showCustomContextMenu(QPoint);
	void openSettingsDialog();

private:
	DialogQwtPlotDetails *DialogQwtPlot;
	bool bAxisScaleIsLog[4];

protected:
	void resizeEvent(QResizeEvent *event);

};

#endif // CUSTOMQWTPLOT_H
