/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef THUMBNAILCONTAINERBASE_HPP
#define THUMBNAILCONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class thumbnailContainerBase : public touchgfx::Container
{
public:
    thumbnailContainerBase();
    virtual ~thumbnailContainerBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setItemSelectedCallback(touchgfx::GenericCallback<int>& callback)
    {
        this->itemSelectedCallback = &callback;
    }
    void setPlayPausePressedCallback(touchgfx::GenericCallback<bool>& callback)
    {
        this->playPausePressedCallback = &callback;
    }

    /*
     * Custom Actions
     */
    virtual void itemSelectedPressed(const touchgfx::AbstractButton& value);

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitItemSelectedCallback(int value)
    {
        if (itemSelectedCallback && itemSelectedCallback->isValid())
        {
            this->itemSelectedCallback->execute(value);
        }
    }
    virtual void emitPlayPausePressedCallback(bool value)
    {
        if (playPausePressedCallback && playPausePressedCallback->isValid())
        {
            this->playPausePressedCallback->execute(value);
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::Image thumbnailBitmap;
    touchgfx::Button selectItemOverlay;
    touchgfx::IconButtonStyle< touchgfx::ImageButtonStyle< touchgfx::ToggleButtonTrigger > > playPauseOverlay;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<thumbnailContainerBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<thumbnailContainerBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<int>* itemSelectedCallback;
    touchgfx::GenericCallback<bool>* playPausePressedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // THUMBNAILCONTAINERBASE_HPP