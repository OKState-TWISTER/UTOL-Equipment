#ifndef DIALOGQWTPLOTDETAILS_H
#define DIALOGQWTPLOTDETAILS_H

class CustomQwtPlot;
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <QDialog>
template <typename T> class QList;
class QShowEvent;

struct CurveData {
	QwtPlotCurve *curve;
	QString strCurveName;
	QwtPlotCurve::CurveStyle style;
	QwtSymbol::Style symbol_style;
	QBrush symbol_brush;
	QPen symbol_pen;
	int symbol_size;
	QColor colorPen;
	double widthPen;
};

namespace Ui {
    class DialogQwtPlotDetails;
}

class DialogQwtPlotDetails : public QDialog
{
	Q_OBJECT

public:
	explicit DialogQwtPlotDetails(CustomQwtPlot *parent = 0);
	~DialogQwtPlotDetails();

private slots:
	void on_pushBttn_Ok_clicked();
	void             applyChanges();
	int              refreshDialog();
	void on_comboBox_Curves_currentIndexChanged(int index);
	void on_comboBox_CurveStyle_currentIndexChanged(int index);
	void on_dSpinBox_CurveWidth_valueChanged(double value);
	void on_comboBox_CurveSymbol_currentIndexChanged(int index);
	void on_iSpinBox_CurveSymbolSize_valueChanged(int value);
	void on_pushBttn_CurveColor_clicked();

private:
	Ui::DialogQwtPlotDetails *ui;
	CustomQwtPlot *parPlot;
	QList<CurveData> listCurveData;

protected:
	void showEvent(QShowEvent* event);

};

#endif // DIALOGQWTPLOTDETAILS_H
