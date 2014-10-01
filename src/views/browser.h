#include <QVBoxLayout>
#include <QWidget>
#include <QTreeView>

// Browser, an abstract class that represents a host or remote file browser
class Browser : public QWidget
{
public:
	Browser(QWidget* parent = 0, Qt::WindowFlags flags = 0);
	virtual ~Browser();

private:
	QVBoxLayout* m_layout;
	QTreeView* m_treeView;
};