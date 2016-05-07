public:


	explicit QWidget( QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags() );
	~QWidget();

	int devType() const Q_DECL_OVERRIDE;

	WId winId() const;
	void createWinId(); // internal, going away
	inline WId internalWinId() const { return data->winid; }
	WId effectiveWinId() const;

	// GUI style setting
	QStyle *style() const;
	void setStyle( QStyle * );
	// Widget types and states

	bool isTopLevel() const;
	bool isWindow() const;

	bool isModal() const;
	Qt::WindowModality windowModality() const;
	void setWindowModality( Qt::WindowModality windowModality );

	bool isEnabled() const;
	bool isEnabledTo( const QWidget * ) const;
	bool isEnabledToTLW() const;

	public Q_SLOTS:
	void setEnabled( bool );
	void setDisabled( bool );
	void setWindowModified( bool );

	// Widget coordinates

public:
	QRect frameGeometry() const;
	const QRect &geometry() const;
	QRect normalGeometry() const;

	int x() const;
	int y() const;
	QPoint pos() const;
	QSize frameSize() const;
	QSize size() const;
	inline int width() const;
	inline int height() const;
	inline QRect rect() const;
	QRect childrenRect() const;
	QRegion childrenRegion() const;

	QSize minimumSize() const;
	QSize maximumSize() const;
	int minimumWidth() const;
	int minimumHeight() const;
	int maximumWidth() const;
	int maximumHeight() const;
	void setMinimumSize( const QSize & );
	void setMinimumSize( int minw, int minh );
	void setMaximumSize( const QSize & );
	void setMaximumSize( int maxw, int maxh );
	void setMinimumWidth( int minw );
	void setMinimumHeight( int minh );
	void setMaximumWidth( int maxw );
	void setMaximumHeight( int maxh );



	QSize sizeIncrement() const;
	void setSizeIncrement( const QSize & );
	void setSizeIncrement( int w, int h );
	QSize baseSize() const;
	void setBaseSize( const QSize & );
	void setBaseSize( int basew, int baseh );

	void setFixedSize( const QSize & );
	void setFixedSize( int w, int h );
	void setFixedWidth( int w );
	void setFixedHeight( int h );

	// Widget coordinate mapping

	QPoint mapToGlobal( const QPoint & ) const;
	QPoint mapFromGlobal( const QPoint & ) const;
	QPoint mapToParent( const QPoint & ) const;
	QPoint mapFromParent( const QPoint & ) const;
	QPoint mapTo( const QWidget *, const QPoint & ) const;
	QPoint mapFrom( const QWidget *, const QPoint & ) const;

	QWidget *window() const;
	QWidget *nativeParentWidget() const;
	inline QWidget *topLevelWidget() const { return window(); }

	// Widget appearance functions
	const QPalette &palette() const;
	void setPalette( const QPalette & );

	void setBackgroundRole( QPalette::ColorRole );
	QPalette::ColorRole backgroundRole() const;

	void setForegroundRole( QPalette::ColorRole );
	QPalette::ColorRole foregroundRole() const;

	const QFont &font() const;
	void setFont( const QFont & );
	QFontMetrics fontMetrics() const;
	QFontInfo fontInfo() const;

#ifndef QT_NO_CURSOR
	QCursor cursor() const;
	void setCursor( const QCursor & );
	void unsetCursor();
#endif

	void setMouseTracking( bool enable );
	bool hasMouseTracking() const;
	bool underMouse() const;

	void setMask( const QBitmap & );
	void setMask( const QRegion & );
	QRegion mask() const;
	void clearMask();

	void render( QPaintDevice *target, const QPoint &targetOffset = QPoint(),
				 const QRegion &sourceRegion = QRegion(),
				 RenderFlags renderFlags = RenderFlags( DrawWindowBackground | DrawChildren ) );

	void render( QPainter *painter, const QPoint &targetOffset = QPoint(),
				 const QRegion &sourceRegion = QRegion(),
				 RenderFlags renderFlags = RenderFlags( DrawWindowBackground | DrawChildren ) );

	Q_INVOKABLE QPixmap grab( const QRect &rectangle = QRect( QPoint( 0, 0 ), QSize( -1, -1 ) ) );

#ifndef QT_NO_GRAPHICSEFFECT
	QGraphicsEffect *graphicsEffect() const;
	void setGraphicsEffect( QGraphicsEffect *effect );
#endif //QT_NO_GRAPHICSEFFECT

#ifndef QT_NO_GESTURES
	void grabGesture( Qt::GestureType type, Qt::GestureFlags flags = Qt::GestureFlags() );
	void ungrabGesture( Qt::GestureType type );
#endif

	public Q_SLOTS:
	void setWindowTitle( const QString & );
#ifndef QT_NO_STYLE_STYLESHEET
	void setStyleSheet( const QString& styleSheet );
#endif
public:
#ifndef QT_NO_STYLE_STYLESHEET
	QString styleSheet() const;
#endif
	QString windowTitle() const;
	void setWindowIcon( const QIcon &icon );
	QIcon windowIcon() const;
	void setWindowIconText( const QString & );
	QString windowIconText() const;
	void setWindowRole( const QString & );
	QString windowRole() const;
	void setWindowFilePath( const QString &filePath );
	QString windowFilePath() const;

	void setWindowOpacity( qreal level );
	qreal windowOpacity() const;

	bool isWindowModified() const;
#ifndef QT_NO_TOOLTIP
	void setToolTip( const QString & );
	QString toolTip() const;
	void setToolTipDuration( int msec );
	int toolTipDuration() const;
#endif
#ifndef QT_NO_STATUSTIP
	void setStatusTip( const QString & );
	QString statusTip() const;
#endif
#ifndef QT_NO_WHATSTHIS
	void setWhatsThis( const QString & );
	QString whatsThis() const;
#endif
#ifndef QT_NO_ACCESSIBILITY
	QString accessibleName() const;
	void setAccessibleName( const QString &name );
	QString accessibleDescription() const;
	void setAccessibleDescription( const QString &description );
#endif

	void setLayoutDirection( Qt::LayoutDirection direction );
	Qt::LayoutDirection layoutDirection() const;
	void unsetLayoutDirection();

	void setLocale( const QLocale &locale );
	QLocale locale() const;
	void unsetLocale();

	inline bool isRightToLeft() const { return layoutDirection() == Qt::RightToLeft; }
	inline bool isLeftToRight() const { return layoutDirection() == Qt::LeftToRight; }

	public Q_SLOTS:
	inline void setFocus() { setFocus( Qt::OtherFocusReason ); }

public:
	bool isActiveWindow() const;
	void activateWindow();
	void clearFocus();

	void setFocus( Qt::FocusReason reason );
	Qt::FocusPolicy focusPolicy() const;
	void setFocusPolicy( Qt::FocusPolicy policy );
	bool hasFocus() const;
	static void setTabOrder( QWidget *, QWidget * );
	void setFocusProxy( QWidget * );
	QWidget *focusProxy() const;
	Qt::ContextMenuPolicy contextMenuPolicy() const;
	void setContextMenuPolicy( Qt::ContextMenuPolicy policy );

	// Grab functions
	void grabMouse();
#ifndef QT_NO_CURSOR
	void grabMouse( const QCursor & );
#endif
	void releaseMouse();
	void grabKeyboard();
	void releaseKeyboard();
#ifndef QT_NO_SHORTCUT
	int grabShortcut( const QKeySequence &key, Qt::ShortcutContext context = Qt::WindowShortcut );
	void releaseShortcut( int id );
	void setShortcutEnabled( int id, bool enable = true );
	void setShortcutAutoRepeat( int id, bool enable = true );
#endif
	static QWidget *mouseGrabber();
	static QWidget *keyboardGrabber();

	// Update/refresh functions
	inline bool updatesEnabled() const;
	void setUpdatesEnabled( bool enable );

#ifndef QT_NO_GRAPHICSVIEW
	QGraphicsProxyWidget *graphicsProxyWidget() const;
#endif

	public Q_SLOTS:
	void update();
	void repaint();

public:
	inline void update( int x, int y, int w, int h );
	void update( const QRect& );
	void update( const QRegion& );

	void repaint( int x, int y, int w, int h );
	void repaint( const QRect & );
	void repaint( const QRegion & );

	public Q_SLOTS:
	// Widget management functions

	virtual void setVisible( bool visible );
	void setHidden( bool hidden );
	void show();
	void hide();

	void showMinimized();
	void showMaximized();
	void showFullScreen();
	void showNormal();

	bool close();
	void raise();
	void lower();

public:
	void stackUnder( QWidget* );
	void move( int x, int y );
	void move( const QPoint & );
	void resize( int w, int h );
	void resize( const QSize & );
	inline void setGeometry( int x, int y, int w, int h );
	void setGeometry( const QRect & );
	QByteArray saveGeometry() const;
	bool restoreGeometry( const QByteArray &geometry );
	void adjustSize();
	bool isVisible() const;
	bool isVisibleTo( const QWidget * ) const;
	inline bool isHidden() const;

	bool isMinimized() const;
	bool isMaximized() const;
	bool isFullScreen() const;

	Qt::WindowStates windowState() const;
	void setWindowState( Qt::WindowStates state );
	void overrideWindowState( Qt::WindowStates state );

	virtual QSize sizeHint() const;
	virtual QSize minimumSizeHint() const;

	QSizePolicy sizePolicy() const;
	void setSizePolicy( QSizePolicy );
	inline void setSizePolicy( QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical );
	virtual int heightForWidth( int ) const;
	virtual bool hasHeightForWidth() const;

	QRegion visibleRegion() const;

	void setContentsMargins( int left, int top, int right, int bottom );
	void setContentsMargins( const QMargins &margins );
	void getContentsMargins( int *left, int *top, int *right, int *bottom ) const;
	QMargins contentsMargins() const;

	QRect contentsRect() const;

public:
	QLayout *layout() const;
	void setLayout( QLayout * );
	void updateGeometry();

	void setParent( QWidget *parent );
	void setParent( QWidget *parent, Qt::WindowFlags f );

	void scroll( int dx, int dy );
	void scroll( int dx, int dy, const QRect& );

	// Misc. functions

	QWidget *focusWidget() const;
	QWidget *nextInFocusChain() const;
	QWidget *previousInFocusChain() const;

	// drag and drop
	bool acceptDrops() const;
	void setAcceptDrops( bool on );

#ifndef QT_NO_ACTION
	//actions
	void addAction( QAction *action );
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
	void addActions( const QList<QAction*> &actions );
#else
	void addActions( QList<QAction*> actions );
#endif
	void insertAction( QAction *before, QAction *action );
	void insertActions( QAction *before, QList<QAction*> actions );
	void removeAction( QAction *action );
	QList<QAction*> actions() const;
#endif

	QWidget *parentWidget() const;

	void setWindowFlags( Qt::WindowFlags type );
	inline Qt::WindowFlags windowFlags() const;
	void overrideWindowFlags( Qt::WindowFlags type );

	inline Qt::WindowType windowType() const;

	static QWidget *find( WId );
	inline QWidget *childAt( int x, int y ) const;
	QWidget *childAt( const QPoint &p ) const;

#if defined(Q_DEAD_CODE_FROM_QT4_X11)
	const QX11Info &x11Info() const;
	Qt::HANDLE x11PictureHandle() const;
#endif

#if defined(Q_DEAD_CODE_FROM_QT4_MAC)
	Qt::HANDLE macQDHandle() const;
	Qt::HANDLE macCGHandle() const;
#endif

	void setAttribute( Qt::WidgetAttribute, bool on = true );
	inline bool testAttribute( Qt::WidgetAttribute ) const;

	QPaintEngine *paintEngine() const Q_DECL_OVERRIDE;

	void ensurePolished() const;

	bool isAncestorOf( const QWidget *child ) const;

#ifdef QT_KEYPAD_NAVIGATION
	bool hasEditFocus() const;
	void setEditFocus( bool on );
#endif

	bool autoFillBackground() const;
	void setAutoFillBackground( bool enabled );

	QBackingStore *backingStore() const;

	QWindow *windowHandle() const;

	static QWidget *createWindowContainer( QWindow *window, QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags() );

	friend class QDesktopScreenWidget;

Q_SIGNALS:
	void windowTitleChanged( const QString &title );
	void windowIconChanged( const QIcon &icon );
	void windowIconTextChanged( const QString &iconText );
	void customContextMenuRequested( const QPoint &pos );

protected:
	// Event handlers
	bool event( QEvent * ) Q_DECL_OVERRIDE;
	virtual void mousePressEvent( QMouseEvent * );
	virtual void mouseReleaseEvent( QMouseEvent * );
	virtual void mouseDoubleClickEvent( QMouseEvent * );
	virtual void mouseMoveEvent( QMouseEvent * );
#ifndef QT_NO_WHEELEVENT
	virtual void wheelEvent( QWheelEvent * );
#endif
	virtual void keyPressEvent( QKeyEvent * );
	virtual void keyReleaseEvent( QKeyEvent * );
	virtual void focusInEvent( QFocusEvent * );
	virtual void focusOutEvent( QFocusEvent * );
	virtual void enterEvent( QEvent * );
	virtual void leaveEvent( QEvent * );
	virtual void paintEvent( QPaintEvent * );
	virtual void moveEvent( QMoveEvent * );
	virtual void resizeEvent( QResizeEvent * );
	virtual void closeEvent( QCloseEvent * );
#ifndef QT_NO_CONTEXTMENU
	virtual void contextMenuEvent( QContextMenuEvent * );
#endif
#ifndef QT_NO_TABLETEVENT
	virtual void tabletEvent( QTabletEvent * );
#endif
#ifndef QT_NO_ACTION
	virtual void actionEvent( QActionEvent * );
#endif

#ifndef QT_NO_DRAGANDDROP
	virtual void dragEnterEvent( QDragEnterEvent * );
	virtual void dragMoveEvent( QDragMoveEvent * );
	virtual void dragLeaveEvent( QDragLeaveEvent * );
	virtual void dropEvent( QDropEvent * );
#endif

	virtual void showEvent( QShowEvent * );
	virtual void hideEvent( QHideEvent * );
	virtual bool nativeEvent( const QByteArray &eventType, void *message, long *result );

	// Misc. protected functions
	virtual void changeEvent( QEvent * );

	int metric( PaintDeviceMetric ) const Q_DECL_OVERRIDE;
	void initPainter( QPainter *painter ) const Q_DECL_OVERRIDE;
	QPaintDevice *redirected( QPoint *offset ) const Q_DECL_OVERRIDE;
	QPainter *sharedPainter() const Q_DECL_OVERRIDE;

	virtual void inputMethodEvent( QInputMethodEvent * );
public:
	virtual QVariant inputMethodQuery( Qt::InputMethodQuery ) const;

	Qt::InputMethodHints inputMethodHints() const;
	void setInputMethodHints( Qt::InputMethodHints hints );

	protected Q_SLOTS:
	void updateMicroFocus();
protected:

	void create( WId = 0, bool initializeWindow = true,
				 bool destroyOldWindow = true );
	void destroy( bool destroyWindow = true,
				  bool destroySubWindows = true );

	virtual bool focusNextPrevChild( bool next );
	inline bool focusNextChild() { return focusNextPrevChild( true ); }
	inline bool focusPreviousChild() { return focusNextPrevChild( false ); }

protected:
	QWidget( QWidgetPrivate &d, QWidget* parent, Qt::WindowFlags f );
private:
	void setBackingStore( QBackingStore *store );

	bool testAttribute_helper( Qt::WidgetAttribute ) const;

	QLayout *takeLayout();



#ifdef Q_OS_MAC
	friend bool qt_mac_is_metal( const QWidget *w );
#endif
	friend Q_WIDGETS_EXPORT QWidgetData *qt_qwidget_data( QWidget *widget );
	friend Q_WIDGETS_EXPORT QWidgetPrivate *qt_widget_private( QWidget *widget );

private:
	Q_DISABLE_COPY( QWidget )
		Q_PRIVATE_SLOT( d_func(), void _q_showIfNotHidden() )

		QWidgetData *data;