import React, {Component} from 'react';
import {Menu, MenuItem, Paper} from 'material-ui';
import {Link} from 'react-router';
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import darkBaseTheme from 'material-ui/styles/baseThemes/darkBaseTheme';
import getMuiTheme from 'material-ui/styles/getMuiTheme';
import Home from 'material-ui/svg-icons/action/home';
import DeviceHub from 'material-ui/svg-icons/hardware/device-hub';
import Storage from 'material-ui/svg-icons/device/storage';
import Extension from 'material-ui/svg-icons/action/extension';
import LinearScale from 'material-ui/svg-icons/editor/linear-scale'

export default class extends Component {
  constructor() {
    super();
  }
  render() {
    return [
      <MuiThemeProvider muiTheme={getMuiTheme(darkBaseTheme)}>
        <div class="nav-bar">
          <Paper style={{height: '100vh'}}>
            <Menu>
              <Link to="/"><MenuItem primaryText="home" leftIcon={<Home />} /></Link>
              <Link to="/experiment"><MenuItem primaryText="experiment" leftIcon={<DeviceHub />} /></Link>
              <Link to="/database"><MenuItem primaryText="database" leftIcon={<Storage />} /></Link>
              <Link to="/component"><MenuItem primaryText="component" leftIcon={<Extension />} /></Link>
              <Link to="/model"><MenuItem primaryText="model" leftIcon={<LinearScale />} /></Link>
            </Menu>
          </Paper>
        </div>,
        <div class="container">
        </div>
      </MuiThemeProvider>
    ]
  }
}
