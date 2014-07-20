#ifndef _H_DIAMOND_WINDOWCANVAS
#define _H_DIAMOND_WINDOWCANVAS 1

#include "Diamond_Defines.h"
#include "Diamond_ICanvas.h"

#include "Rock.h"
#include "Chalk.h"

namespace Diamond {

    class Core;

    class DIAMOND_API WindowCanvas : public ICanvas {
    public:
        WindowCanvas(Core* pCore, IDevice* pDevice);
        virtual ~WindowCanvas();

        Core* GetCore();
        Core const* GetCore() const;

        void Init(RINT hWnd, RUINT nWidth, RUINT nHeight, RBOOL bFullscreen);

        virtual void Activate();

    private:
        PIMPL_DECL(WindowCanvas);
        CLASS_NOCOPY(WindowCanvas);
    };
};

#endif // _H_DIAMOND_WINDOWCANVAS